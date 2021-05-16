#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include "review.h"

Review::Review(QWidget* parent)
    : QWidget(parent) {

    QGridLayout* grid = new QGridLayout(this);
    grid->setVerticalSpacing(15);
    grid->setHorizontalSpacing(10);

    QLabel* title = new QLabel("Title:", this);
    grid->addWidget(title, 0, 0, 1, 1);
    title->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit* edt1 = new QLineEdit(this);
    grid->addWidget(edt1, 0, 1, 1, 1);

    QLabel* author = new QLabel("Author:", this);
    grid->addWidget(author, 1, 0, 1, 1);
    author->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit* edt2 = new QLineEdit(this);
    grid->addWidget(edt2, 1, 1, 1, 1);

    QLabel* review = new QLabel("Review:", this);
    grid->addWidget(review, 2, 0, 1, 1);
    review->setAlignment(Qt::AlignRight | Qt::AlignTop);

    QTextEdit* te = new QTextEdit(this);
    grid->addWidget(te, 2, 1, 3, 1);

    setLayout(grid);
}