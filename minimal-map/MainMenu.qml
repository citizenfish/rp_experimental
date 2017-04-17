import QtQuick 2.5
import QtQuick.Controls 1.4
import QtLocation 5.6

MenuBar {
        property variant routeMenu: routeMenu
        Menu {
            id: routeMenu
            title:"Route"
            MenuItem { text: "Create Route"}
            MenuItem { text: "Load Route" }
            }
}
