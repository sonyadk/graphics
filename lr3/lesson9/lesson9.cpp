
#include <windows.h>	
#include <gl\gl.h>		
#include <gl\glu.h>		
#include <gl\glaux.h>	

static	HGLRC hRC;		
static	HDC hDC;		

BOOL	keys[256];		
BOOL	twinkle;		
BOOL	tp;				

const	num=50;			

typedef struct			
{
	int r, g, b;		
	GLfloat dist,		
			angle;		
}
stars;
stars star[num];		

GLfloat	zoom=-15.0f;	
GLfloat tilt=0.0f;		
GLfloat	spin;			

GLuint	loop;			
GLuint	texture[1];		


GLvoid LoadGLTextures()
{
	
	AUX_RGBImageRec *texture1;

	texture1 = auxDIBImageLoad("Data/star.bmp");
	if (!texture1)
	{
		exit(1);
	}

	glGenTextures(1, &texture[0]);				

	
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
};

GLvoid InitGL(GLsizei Width, GLsizei Height)	
{
	LoadGLTextures();							
	glEnable(GL_TEXTURE_2D);					

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		
	glClearDepth(1.0);							
	glShadeModel(GL_SMOOTH);					

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();							

	gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	

	glMatrixMode(GL_MODELVIEW);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);			
	glEnable(GL_BLEND);

	for (loop=0; loop<num; loop++)
	{
		star[loop].angle=0.0f;
		star[loop].dist=(float(loop)/num)*5.0f;
		star[loop].r=rand()%256;
		star[loop].g=rand()%256;
		star[loop].b=rand()%256;
	}
}

GLvoid ReSizeGLScene(GLsizei Width, GLsizei Height)
{
	if (Height==0)								
		Height=1;

	glViewport(0, 0, Width, Height);			

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
}

GLvoid DrawGLScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	for (loop=0; loop<num; loop++)
	{
		glLoadIdentity();
		glTranslatef(0.0f,0.0f,zoom);
		
		glRotatef(tilt,1.0f,0.0f,0.0f);
		
		
		glRotatef(star[loop].angle,0.0f,0.0f,1.0f);
		
		glTranslatef(star[loop].dist,0.0f,0.0f);
	
		glRotatef(-star[loop].angle,0.0f,0.0f,1.0f);
	
		glRotatef(-tilt,1.0f,0.0f,0.0f);
	
		
		if (twinkle)
		{

		glColor4ub(star[loop].r,star[loop].g,star[loop].b,255);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,-1.0f, 0.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
			glEnd();
		}
	
		glRotatef(spin,0.0f,0.0f,1.0f);
	
		glColor4ub(star[loop].r,star[loop].g,star[loop].b,255);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();

		spin+=0.01f;
		star[loop].angle+=float(loop)/num;
		star[loop].dist-=0.01f;
		if (star[loop].dist<0.0f)
		{
			star[loop].dist+=5.0f;
			star[loop].r=rand()%256;
			star[loop].g=rand()%256;
			star[loop].b=rand()%256;
		}
	}
}

LRESULT CALLBACK WndProc(	HWND	hWnd,
				UINT	message,
				WPARAM	wParam,
				LPARAM	lParam)
{
	RECT	Screen;							
	GLuint	PixelFormat;
	static	PIXELFORMATDESCRIPTOR pfd=
	{
		sizeof(PIXELFORMATDESCRIPTOR),		
		1,									
		PFD_DRAW_TO_WINDOW |				
		PFD_SUPPORT_OPENGL |				
		PFD_DOUBLEBUFFER,					
		PFD_TYPE_RGBA,						
		16,									
		0, 0, 0, 0, 0, 0,					
		0,									
		0,									
		0,									
		0, 0, 0, 0,							
		16,									
		0,									
		0,									
		PFD_MAIN_PLANE,						
		0,									
		0, 0, 0								
	};

	switch (message)						
	{
		case WM_CREATE:
			hDC = GetDC(hWnd);				
			PixelFormat = ChoosePixelFormat(hDC, &pfd);		

			if (!PixelFormat)
			{
				MessageBox(0,"Can't Find A Suitable PixelFormat.","Error",MB_OK|MB_ICONERROR);
				PostQuitMessage(0);			
				break;						
			}

			if(!SetPixelFormat(hDC,PixelFormat,&pfd))
			{
				MessageBox(0,"Can't Set The PixelFormat.","Error",MB_OK|MB_ICONERROR);
				PostQuitMessage(0);
				break;
			}

			hRC = wglCreateContext(hDC);
			if(!hRC)
			{
				MessageBox(0,"Can't Create A GL Rendering Context.","Error",MB_OK|MB_ICONERROR);
				PostQuitMessage(0);
				break;
			}

			if(!wglMakeCurrent(hDC, hRC))
			{
				MessageBox(0,"Can't activate GLRC.","Error",MB_OK|MB_ICONERROR);
				PostQuitMessage(0);
				break;
			}

			GetClientRect(hWnd, &Screen);
			InitGL(Screen.right, Screen.bottom);
			break;

		case WM_DESTROY:
		case WM_CLOSE:
			ChangeDisplaySettings(NULL, 0);

			wglMakeCurrent(hDC,NULL);
			wglDeleteContext(hRC);
			ReleaseDC(hWnd,hDC);

			PostQuitMessage(0);
			break;

		case WM_KEYDOWN:
			keys[wParam] = TRUE;
			break;

		case WM_KEYUP:
			keys[wParam] = FALSE;
			break;

		case WM_SIZE:
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));
			break;

		default:
			return (DefWindowProc(hWnd, message, wParam, lParam));
	}
return (0);
}

int WINAPI WinMain(	HINSTANCE	hInstance, 
			HINSTANCE	hPrevInstance, 
			LPSTR		lpCmdLine, 
			int			nCmdShow)
{
	MSG			msg;		
	WNDCLASS	wc;			
	HWND		hWnd;		

	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc		= (WNDPROC) WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInstance;
	wc.hIcon			= NULL;
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= NULL;
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= "OpenGL WinClass";

	if(!RegisterClass(&wc))
	{
		MessageBox(0,"Failed To Register The Window Class.","Error",MB_OK|MB_ICONERROR);
		return FALSE;
	}

	hWnd = CreateWindow(
	"OpenGL WinClass",
	"Jeff Molofee's GL Code Tutorial ... NeHe '99",		

	WS_POPUP |
	WS_CLIPCHILDREN |
	WS_CLIPSIBLINGS,

	0, 0,												
	640, 480,											

	NULL,
	NULL,
	hInstance,
	NULL);

	if(!hWnd)
	{
		MessageBox(0,"Window Creation Error.","Error",MB_OK|MB_ICONERROR);
		return FALSE;
	}

	DEVMODE dmScreenSettings;											

	memset(&dmScreenSettings, 0, sizeof(DEVMODE));						
	dmScreenSettings.dmSize			= sizeof(DEVMODE);					
	dmScreenSettings.dmPelsWidth	= 640;								
	dmScreenSettings.dmPelsHeight	= 480;								
	dmScreenSettings.dmFields		= DM_PELSWIDTH | DM_PELSHEIGHT;		
	ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);			

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	SetFocus(hWnd);
	wglMakeCurrent(hDC,hRC);

	while (1)
	{
		
		while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				return TRUE;
			}
		}

		DrawGLScene();
		SwapBuffers(hDC);
		if (keys[VK_ESCAPE]) SendMessage(hWnd,WM_CLOSE,0,0);

		if (keys['T'] && !tp)
		{
			tp=TRUE;
			twinkle=!twinkle;
		}
		if (!keys['T'])
		{
			tp=FALSE;
		}

		if (keys[VK_UP])
		{
			tilt-=0.5f;
		}

		if (keys[VK_DOWN])
		{
			tilt+=0.5f;
		}

		if (keys[VK_PRIOR])
		{
			zoom-=0.2f;
		}

		if (keys[VK_NEXT])
		{
			zoom+=0.2f;
		}
	}
}
