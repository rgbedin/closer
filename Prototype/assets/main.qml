// Tabbed Pane project template
import bb.cascades 1.0
import bb.cascades.pickers 1.0

TabbedPane {
    showTabsOnActionBar: true
    Tab {
        title: qsTr("Wallet")
        Page {
            id: tab1
            Container {
                ImageView {
                    id: backgroundImage0
                    objectName: "backgroundImage"
                    imageSource: "asset:///images/background.png"
                    scalingMethod: ScalingMethod.Fill
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                }
            }
        }
    }
    Tab {
        title: qsTr("My Cards")
        Page {
            id: tab2
            Container {
                ImageView {
                    id: backgroundImage1
                    objectName: "backgroundImage"
                    imageSource: "asset:///images/background.png"
                    scalingMethod: ScalingMethod.Fill
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                }
                layout: DockLayout {
                }

                // Main List
                ListView {
                    id: personalCardList
                    layout: GridListLayout {
                        columnCount: 2
                        headerMode: ListHeaderMode.Standard
                        cellAspectRatio: 1.4
                        spacingAfterHeader: 20
                        verticalCellSpacing: 0
                    }

                    // This data model will be replaced by a JSON model when the application starts,
                    // an XML model can be used to prototype the UI and for smaller static lists.
                    dataModel: XmlDataModel {
                        source: "models/mycards.xml"
                    }
                    listItemComponents: [
                        ListItemComponent {
                            type: "header"
                            Header {
                                title: Title //{
                                //                                    // if (ListItemData.title) {
                                //                                    // If the data is loaded from XML, a title property is used for the title.
                                //                                    ListItemData.title
                                //                                    // } else {
                                //                                    // // If it is loaded from JSON and set in a GroupDataModel, the header info is set in ListItemData.
                                //                                    // ListItemData
                                //                                    // }
                                //                                }
                            }
                        },
                        ListItemComponent {
                            type: "card"
                            CardItem {
                                verticalAlignment: VerticalAlignment.Center
                                horizontalAlignment: HorizontalAlignment.Center
                            }
                        }
                    ]
                    leftPadding: 80.0
                    topPadding: 150.0

                    // listItemComponents
                    //                    onTriggered: {
                    //
                    //                        // To avoid triggering navigation when pressing the header items, we check so that the
                    //                        // index path length is larger then one (one entry would be a group under a header item).
                    //                        if (indexPath.length > 1) {
                    //                            // When an item is selected we push the recipe Page in the chosenItem file attribute.
                    //                            var chosenItem = dataModel.data(indexPath);
                    //
                    //                            // Create the content page and push it on top to drill down to it.
                    //                            var contentpage = contentPageDefinition.createObject();
                    //
                    //                            // Set the content properties to reflect the selected image.
                    //                            contentpage.contentImageURL = chosenItem.URL
                    //                            contentpage.contentDescription = chosenItem.infoText
                    //
                    //                            // Push the content page to the navigation stack
                    //                            nav.push(contentpage);
                    //                        }
                    //                    }
                }
            }
        }
    }
    Tab {
        title: qsTr("Card Creator")
        Page {
            id: tab3
            Container {
                ImageView {
                    id: backgroundImage2
                    objectName: "backgroundImage"
                    imageSource: "asset:///images/background.png"
                    scalingMethod: ScalingMethod.Fill
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                }
                layout: DockLayout {
                }
                Container {
                    id: menuContainer
                    //background: Color.create ("#262626")
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    verticalAlignment: VerticalAlignment.Bottom
                    horizontalAlignment: HorizontalAlignment.Center
                    bottomPadding: 25.0
                    ImageButton {
                        defaultImageSource: "asset:///images/text_icon.png"
                        //pressedImageSource: "asset:///myPressedImage.png"
                        //disabledImageSource: "asset:///myDisabledImage.png"
                        property int num: 1
                        onClicked: {
                            if (num == 1) {
                                textContainer.setVisible(true);
                                num = 0;
                            } else {
                                textContainer.setVisible(false);
                                num = 1;
                            }
                        }
                    }
                    Button {
                        text: "TCOLOR"
                        onClicked: {
                        }
                        preferredWidth: 25.0
                    }
                    ImageButton {
                        defaultImageSource: "asset:///images/picture_icon.png"
                        onClicked: {
                            picker.open()
                        }
                    }
                    Button {
                        text: "SOCIAL"
                        onClicked: {
                        }
                        preferredWidth: 25.0
                    }
                    Button {
                        objectName: "doneButton"
                        text: "DONE"
                        onClicked: {
                            _closer.writeXML(name.text, email.text, title.text, "test");
                        }
                        preferredWidth: 25.0
                    }
                }
                Container {
                    id: textContainer
                    property real dy: 0
                    property real dx: 0
                    property real currentY: 0
                    property real currentX: 0
                    property real lastX: 0
                    property real lastY: 0
                    layout: StackLayout {
                        orientation: LayoutOrientation.TopToBottom
                    }
                    verticalAlignment: VerticalAlignment.Top
                    horizontalAlignment: HorizontalAlignment.Center
                    preferredWidth: 400.0
                    preferredHeight: 150.0
                    topPadding: 25.0
                    TextField {
                        id: name
                        inputMode: TextFieldInputMode.Text
                        hintText: "Name"
                        textStyle.textAlign: TextAlign.Center
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontWeight: FontWeight.Normal
                        textStyle.fontStyle: FontStyle.Normal
                        textStyle.fontSizeValue: 5.0
                        preferredWidth: 380.0
                        leftPadding: 0.0
                        rightPadding: 0.0
                        backgroundVisible: false
                    }
                    TextField {
                        id: email
                        inputMode: TextFieldInputMode.EmailAddress
                        hintText: "Email"
                        textStyle.textAlign: TextAlign.Center
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontWeight: FontWeight.Normal
                        textStyle.fontStyle: FontStyle.Normal
                        textStyle.fontSizeValue: 5.0
                        preferredWidth: 380.0
                        backgroundVisible: false
                    }
                    TextField {
                        id: title
                        inputMode: TextFieldInputMode.Text
                        hintText: "Corporate Title"
                        textStyle.textAlign: TextAlign.Center
                        textStyle.fontSize: FontSize.PointValue
                        textStyle.fontWeight: FontWeight.Normal
                        textStyle.fontStyle: FontStyle.Normal
                        textStyle.fontSizeValue: 5.0
                        preferredWidth: 380.0
                        backgroundVisible: false
                    }
                    onTouch: {

                        // disable implicit animations (?)
                        translationControllerY.enabled = false;
                        translationControllerX.enabled = false;
                        if (event.isDown()) {
                            // user initiates the touch event
                            // saves the current coordinate
                            dx = event.windowX;
                            dy = event.windowY;
                        } else if (event.isMove()) {
                            // user is moving the object
                            // sets the new position of the object
                            currentY = event.windowY - dy;
                            currentX = event.windowX - dx;
                            translationY = currentY;
                            translationX = currentX;
                            // saves the location of the last touch
                            lastX = event.windowX;
                            lastY = event.windowY;
                        } else if (event.isUp()) {
                            // call to add text
                            // user released the object
                        }

                        // re-enabling the implicit animations (?)
                        translationControllerY.enabled = true;
                        translationControllerX.enabled = true;
                    }
                    attachedObjects: [
                        ImplicitAnimationController {
                            id: translationControllerY
                            propertyName: "translationY"
                        },
                        ImplicitAnimationController {
                            id: translationControllerX
                            propertyName: "translationX"
                        }
                    ]
                    visible: false
                }
            }
            attachedObjects: [
                // file picker object to choose the background picture
                FilePicker {
                    id: picker
                    property string selectedFile
                    title: qsTr("Image Picker")
                    mode: FilePickerMode.Picker
                    type: FileType.Picture
                    viewMode: FilePickerViewMode.Default
                    sortBy: FilePickerSortFlag.Default
                    sortOrder: FilePickerSortOrder.Default
                    onFileSelected: {
                        // grab the file selected
                        selectedFile = selectedFiles[0];
                        console.log("File Selected: " + selectedFile);
                        // set as background image
                        backgroundImage2.imageSource = selectedFile;
                    }
                }
            ]
        }
    }
    onCreationCompleted: {
        // this slot is called when declarative scene is created
        // write post creation initialization here
        console.log("TabbedPane - onCreationCompleted()")

        // enable layout to adapt to the device rotation
        // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
        OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
    }
}
