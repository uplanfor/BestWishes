#include "customframe.h"

CustomFrame::CustomFrame(QWidget *content, QWidget *parent) :
    QWidget(parent),
    m_boundary(7), can_resize(true), can_move(true)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    m_container = content;
    m_container->setParent(this);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(1, 1, 1, 1);
    verticalLayout->addWidget(m_container);
}

CustomFrame::~CustomFrame()
{
    delete m_container;
}

bool CustomFrame::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    if (!can_resize)
    {
        return false;
    }
    MSG *msg = (MSG *)message;
    switch (msg->message)
    {
    case WM_NCHITTEST:
        int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
        int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
        if (xPos < m_boundary && yPos < m_boundary)
            *result = HTTOPLEFT;
        else if (xPos >= width() - m_boundary && yPos < m_boundary)
            *result = HTTOPRIGHT;
        else if (xPos < m_boundary && yPos >= height() - m_boundary)
            *result = HTBOTTOMLEFT;
        else if (xPos >= width() - m_boundary && yPos >= height() - m_boundary)
            *result = HTBOTTOMRIGHT;
        else if (xPos < m_boundary)
            *result = HTLEFT;
        else if (xPos >= width() - m_boundary)
            *result = HTRIGHT;
        else if (yPos < m_boundary)
            *result = HTTOP;
        else if (yPos >= height() - m_boundary)
            *result = HTBOTTOM;
        else
            return false;
        return true;
    }
    return false;
}


void CustomFrame::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton && can_move)
    {
        pressPos = ev->pos();
    }
}


void CustomFrame::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::LeftButton & can_move)
        move(ev->pos() + this->pos() - pressPos);
}


void CustomFrame::setBoundary(int boundary)
{
    if (boundary > 7)
    {
        m_boundary = boundary;
    }
}


int CustomFrame::getBoundary()
{
    return m_boundary;
}


QWidget* CustomFrame::container()
{
    return m_container;
}


QWidget* CustomFrame::operator->()
{
    return m_container;
}


void CustomFrame::setMovable(bool status)
{
    can_move = status;
}


void CustomFrame::setResizable(bool status)
{
    can_resize = status;
}
