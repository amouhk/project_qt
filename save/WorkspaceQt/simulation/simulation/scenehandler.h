#ifndef SCENEHANDLER_H
#define SCENEHANDLER_H
class SceneHandler;
#include <QUndoStack>
#include <QXmlDefaultHandler>
#include "scene.h"

class SceneHandler : public QXmlDefaultHandler
{
public:
    SceneHandler(Scene* scene, QUndoStack* undoStack);
    virtual bool startDocument();
    virtual bool startElement(const QString &namespaceURI,
                              const QString &localName,
                              const QString &qName,
                              const QXmlAttributes &atts);
    virtual bool endElement(const QString &namespaceURI,
                            const QString &localName,
                            const QString &qName);
    virtual bool endDocument();
private:
    Scene* scene;
    QUndoStack* undoStack;
};

#endif // SCENEHANDLER_H
