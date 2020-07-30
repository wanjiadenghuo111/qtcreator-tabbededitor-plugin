#ifndef PLUGIN_H
#define PLUGIN_H

#include <extensionsystem/iplugin.h>

namespace TabbedEditor
{
namespace Internal
{

class TabBar;

class TabbedEditorPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "TabbedEditor.json")
public:
    TabbedEditorPlugin();

    bool initialize(const QStringList& arguments, QString* errorString);
    void extensionsInitialized() {}
    bool delayedInitialize() ;

private slots:
    QString getStylesheetPatternFromFile(const QString& filepath);
    void updateStyleToBaseColor();
    void showTabBar();

private:
    static inline QString getQssStringFromColor(const QColor& color);

    TabBar* m_tabBar;
    bool m_styleUpdatedToBaseColor;
};

} // namespace Internal
} // namespace TabbedEditor

#endif // PLUGIN_H
