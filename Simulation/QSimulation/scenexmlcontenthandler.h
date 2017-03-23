#ifndef SCENEXMLCONTENTHANDLER_H
#define SCENEXMLCONTENTHANDLER_H


#include <QXmlDefaultHandler>
#include <QUndoStack>
#include "scene.h"

namespace Model
{

    class SceneXmlContentHandler : public QXmlDefaultHandler
    {
    public:
        SceneXmlContentHandler(QUndoStack* undoStack, Scene* scene);
        virtual ~SceneXmlContentHandler();

        virtual bool startDocument();
        virtual bool startElement(const QString &namespaceURI, const QString &localName,
                                  const QString &qName, const QXmlAttributes &atts);
        virtual bool endElement(const QString &namespaceURI, const QString &localName,
                                const QString &qName);
        virtual bool endDocument();

    private:
        QUndoStack* mp_undoStack;
        Scene*      mp_scene;

    };

}

#endif // SCENEXMLCONTENTHANDLER_H
