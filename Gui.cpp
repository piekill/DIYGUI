#include "Gui.h"
#include <QDomElement>
void Gui::setattrib(const QDomElement &node)
{
    if(node.tagName()=="label")_label=node.text();
    else if(node.tagName()=="icon")_icon.addFile(node.text());
    else if(node.tagName()=="cmd")_cmd=node.text();
    else if(node.tagName()=="memo")_memo=node.text();
    else return;
}
