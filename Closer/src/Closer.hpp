// Default empty project template
#ifndef Closer_HPP_
#define Closer_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class Closer : public QObject
{
    Q_OBJECT
public:
    Closer(bb::cascades::Application *app);
    virtual ~Closer() {}

public Q_SLOTS:
    void test(const QString &qmlString);
    void addText(float posX, float posY);
    void showSocialNetworkPicker();
};


#endif /* Closer_HPP_ */
