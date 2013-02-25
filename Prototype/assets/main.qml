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

                // define tab content here
                Label {
                    text: qsTr("Tab 1 title")
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
                ImageView {
                    id: imgTab1
                    imageSource: "asset:///images/picture1.png"
                    layoutProperties: StackLayoutProperties {
                        // make imageView to fill all available height
                        spaceQuota: 1.0
                    }
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                    scalingMethod: ScalingMethod.AspectFit
                }
            }
        }
    }
    Tab {
        title: qsTr("My Cards")
        Page {
            id: tab2
            Container {

                // define tab content here
                Label {
                    text: qsTr("Tab 2 title")
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
                ImageView {
                    id: imgTab2
                    imageSource: "asset:///images/picture1.png"
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1.0
                    }
                    scalingMethod: ScalingMethod.AspectFit
                    opacity: 0.2
                    animations: [
                        // define animations for image here
                        ParallelAnimation {
                            id: raiseAnimation
                            FadeTransition {
                                fromOpacity: 0.2
                                toOpacity: 1
                                duration: 1000
                            }
                            ScaleTransition {
                                fromX: 1
                                fromY: 1
                                toX: 1.5
                                toY: 1.5
                                duration: 1000
                                easingCurve: StockCurve.DoubleElasticOut
                            }
                        }
                    ]
                }
            }
        }
    }
    Tab {
        title: qsTr("Card Creator")
        Page {
            id: tab3

            // define tab content here
            Container {
                objectName: "rootContainer"
                layout: AbsoluteLayout {
                }

                // background image
                ImageView {
                    id: backgroundImage
                    objectName: "backgroundImage"
                    imageSource: "asset:///images/background.png"
                    preferredWidth: 768
                    preferredHeight: 1280
                    scalingMethod: ScalingMethod.AspectFill
                }

                // draggable text icon
                ImageView {
                    id: textIcon

                    // dragging properties of the text icon
                    property real dy: 0
                    property real dx: 0
                    property real currentY: 0
                    property real currentX: 0
                    property real lastX: 0
                    property real lastY: 0

                    // source of the text icon
                    imageSource: "asset:///images/text_icon.png"

                    // layout properties of the text icon
                    layoutProperties: AbsoluteLayoutProperties {
                        positionX: 50
                        positionY: 1000
                    }

                    // animation that will be played when the icon is released
                    animations: [
                        TranslateTransition {
                            id: resetTextIcon
                            toY: 0
                            toX: 0
                            duration: 400
                        }
                    ]
                    onTouchExit: {
                        // call to add text
                        _closer.addText(lastX, lastY);
                        // release the text icon when stopping touch
                        releaseTextIcon();
                    }

                    // touch even of the text icon
                    onTouch: {
                        // disable implicit animations (?)
                        translationControllerY.enabled = false;
                        translationControllerX.enabled = false;
                        if (event.isDown()) {
                            // stop the reset animation
                            resetTextIcon.stop();

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
                            _closer.addText(lastX, lastY);
                            // user released the object
                            releaseTextIcon();
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
                }

                // draggable picture icon
                ImageView {
                    id: pictureIcon

                    // dragging properties of the icon
                    property real dy: 0
                    property real dx: 0
                    property real currentY: 0
                    property real currentX: 0
                    property real lastX: 0
                    property real lastY: 0

                    // source of the icon
                    imageSource: "asset:///images/picture_icon.png"

                    // layout properties of the icon
                    layoutProperties: AbsoluteLayoutProperties {
                        positionX: 200
                        positionY: 1000
                    }

                    // animation that will be played when the icon is released
                    animations: [
                        TranslateTransition {
                            id: resetPictureIcon
                            toY: 0
                            toX: 0
                            duration: 400
                        }
                    ]
                    onTouchExit: {
                        // call to picker
                        picker.open();
                        // release the text icon when stopping touch
                        releasePictureIcon();
                    }

                    // touch even of the icon
                    onTouch: {
                        // disable implicit animations (?)
                        translationControllerPictureY.enabled = false;
                        translationControllerPictureX.enabled = false;
                        if (event.isDown()) {
                            // stop the reset animation
                            resetPictureIcon.stop();

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
                            // call to picker
                            picker.open();
                            // user released the object
                            releasePictureIcon();
                        }

                        // re-enabling the implicit animations (?)
                        translationControllerPictureY.enabled = true;
                        translationControllerPictureX.enabled = true;
                    }
                    attachedObjects: [
                        ImplicitAnimationController {
                            id: translationControllerPictureY
                            propertyName: "translationY"
                        },
                        ImplicitAnimationController {
                            id: translationControllerPictureX
                            propertyName: "translationX"
                        }
                    ]
                }
            }
            function releaseTextIcon() {
                // check if the text icon is not at its original position
                if (textIcon.translationY != 0 || textIcon.translationX != 0) {
                    // if it is not, play the reset animation
                    resetTextIcon.play();
                }
            }
            function releasePictureIcon() {
                // check if the picture icon is not at its original position
                if (pictureIcon.translationY != 0 || pictureIcon.translationX != 0) {
                    // if it is not, play the reset animation
                    resetPictureIcon.play();
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
                        backgroundImage.imageSource = selectedFile;
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
