/*========================================================================================

  Name:   ARB_multisample.cpp
	Author: Colt "MainRoach" McAnlis
	Date:   4/29/04
	Desc:   This file contains the context to load a WGL extension from a string
		    As well as collect the sample format available based upon the graphics card.

========================================================================================*/

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "arb_multisample.h"


#define WGL_SAMPLE_BUFFERS_ARB		 0x2041
#define WGL_SAMPLES_ARB			     0x2042

bool	arbMultisampleSupported	= false;
int		arbMultisampleFormat	= 0;


bool WGLisExtensionSupported(const char *extension)
{
	const size_t extlen = strlen(extension);
	const char *supported = NULL;

	
	PROC wglGetExtString = wglGetProcAddress("wglGetExtensionsStringARB");

	if (wglGetExtString)
		supported = ((char*(__stdcall*)(HDC))wglGetExtString)(wglGetCurrentDC());

	
	if (supported == NULL)
		supported = (char*)glGetString(GL_EXTENSIONS);

	
	if (supported == NULL)
		return false;

	
	for (const char* p = supported; ; p++)
	{
		
		p = strstr(p, extension);

		if (p == NULL)
			return false;															

		
		
		

		
		
		if ((p==supported || p[-1]==' ') && (p[extlen]=='\0' || p[extlen]==' '))
			return true;															
	}
}


bool InitMultisample(HINSTANCE hInstance,HWND hWnd,PIXELFORMATDESCRIPTOR pfd)
{  
	 
	if (!WGLisExtensionSupported("WGL_ARB_multisample"))
	{
		arbMultisampleSupported=false;
		return false;
	}

	
	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");	
	if (!wglChoosePixelFormatARB) 
	{
		arbMultisampleSupported=false;
		return false;
	}

	
	HDC hDC = GetDC(hWnd);

	int		pixelFormat;
	int		valid;
	UINT	numFormats;
	float	fAttributes[] = {0,0};

	
	
	
	
	
	int iAttributes[] =
	{
		WGL_DRAW_TO_WINDOW_ARB,GL_TRUE,
		WGL_SUPPORT_OPENGL_ARB,GL_TRUE,
		WGL_ACCELERATION_ARB,WGL_FULL_ACCELERATION_ARB,
		WGL_COLOR_BITS_ARB,24,
		WGL_ALPHA_BITS_ARB,8,
		WGL_DEPTH_BITS_ARB,16,
		WGL_STENCIL_BITS_ARB,0,
		WGL_DOUBLE_BUFFER_ARB,GL_TRUE,
		WGL_SAMPLE_BUFFERS_ARB,GL_TRUE,
		WGL_SAMPLES_ARB,4,
		0,0
	};

	
	valid = wglChoosePixelFormatARB(hDC,iAttributes,fAttributes,1,&pixelFormat,&numFormats);
 
	
	if (valid && numFormats >= 1)
	{
		arbMultisampleSupported = true;
		arbMultisampleFormat = pixelFormat;	
		return arbMultisampleSupported;
	}

	
	iAttributes[19] = 2;
	valid = wglChoosePixelFormatARB(hDC,iAttributes,fAttributes,1,&pixelFormat,&numFormats);
	if (valid && numFormats >= 1)
	{
		arbMultisampleSupported = true;
		arbMultisampleFormat = pixelFormat;	 
		return arbMultisampleSupported;
	}
	  
	
	return  arbMultisampleSupported;
}
