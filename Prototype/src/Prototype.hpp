// Tabbed pane project template
#ifndef Prototype_HPP_
#define Prototype_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class Prototype : public QObject
{
    Q_OBJECT
public:
    Prototype(bb::cascades::Application *app);
    virtual ~Prototype() {}

public Q_SLOTS:
    void addText(float posX, float posY);
    void showSocialNetworkPicker();
};

#endif /* Prototype_HPP_ */