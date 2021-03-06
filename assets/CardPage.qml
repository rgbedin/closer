import bb.cascades 1.0

Page {
    id: cardPage

    //company varchar(30), name varchar(30), corporateTitle varchar(30), email varchar(60), phone varchar(30), address varchar(90), aboutMe varchar(120), linkedinProfile varchar(120));
    property string company
    property string name
    property string corporateTitle
    property string email
    property string phone
    property string address
    property string aboutMe;
    //    property string linkedinProfiles;
    signal deleteQuote()
    signal updateQuote(string firstName, string lastName, string quote)
    signal back();
    //signal cardPageClose()
    Container {
        id: container
        property bool editMode: false
        layout: AbsoluteLayout {
        }
        background: Color.create("#333333")
        preferredWidth: 200.0
        //Better way to set background picture
        //         background: backgroundPaint.imagePaint
        //
        //                attachedObjects: [
        //                    ImagePaintDefinition {
        //                        id: backgroundPaint
        //                        imageSource: "asset:///images/background.png"
        //                    }
        //                ]
        Container {
            background: Color.create("#333333")
            preferredWidth: 728.0
            preferredHeight: 140.0
            translationX: 20.0
            layout: DockLayout {
            }
            Label {
                id: companyLabel
                text: company
                textStyle.fontSize: FontSize.XLarge
                textStyle.fontFamily: "Verdana"
                textStyle.textAlign: TextAlign.Center
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                textStyle.color: Color.White
            }
        }
        Container {
            background: Color.create("#FFFFFF")
            preferredWidth: 728.0
            preferredHeight: 400.0
            translationX: 20.0
            translationY: 140.0
            layout: AbsoluteLayout {
            }
            Container {
                background: Color.create("#FFFFFF")
                preferredWidth: 364.0
                preferredHeight: 400.0
                translationX: 0.0
                translationY: 0.0
                layout: DockLayout {
                }
                Label {
                    id: nameLabel
                    text: name
                    translationY: 150.0
                    textStyle.fontSize: FontSize.Large
                    textStyle.fontFamily: "Verdana"
                    textStyle.textAlign: TextAlign.Center
                    horizontalAlignment: HorizontalAlignment.Center
                }
                Label {
                    id: corporateTitleLabel
                    text: corporateTitle
                    translationY: 40.0
                    textStyle.fontSize: FontSize.Small
                    textStyle.fontFamily: "Verdana"
                    textStyle.textAlign: TextAlign.Center
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                }
            }
            Container {
                background: Color.create("#FFFFFF")
                preferredWidth: 384.0
                preferredHeight: 400.0
                translationX: 344.0
                translationY: 0.0
                layout: DockLayout {
                }
                Label {
                    id: emailLabel
                    text: email
                    translationY: 40.0
                    textStyle.fontSize: FontSize.Medium
                    textStyle.fontFamily: "Verdana"
                    textStyle.textAlign: TextAlign.Center
                    horizontalAlignment: HorizontalAlignment.Center
                }
                Label {
                    id: phoneLabel
                    text: phone
                    translationY: 160.0
                    textStyle.fontSize: FontSize.Medium
                    textStyle.fontFamily: "Verdana"
                    textStyle.textAlign: TextAlign.Center
                    horizontalAlignment: HorizontalAlignment.Center
                }
                Label {
                    id: addressLabel
                    text: address
                    translationY: 280.0
                    textStyle.fontSize: FontSize.Medium
                    textStyle.fontFamily: "Verdana"
                    textStyle.textAlign: TextAlign.Center
                    horizontalAlignment: HorizontalAlignment.Center
                }
            }
        }
        Container {
            background: Color.create("#333333")
            preferredWidth: 728.0
            preferredHeight: 290.0
            translationX: 20.0
            translationY: 560.0
            layout: AbsoluteLayout {
            }
            Label {
                text: "About Me"
                translationX: 280.0
                textStyle.color: Color.White
                textStyle.fontFamily: "Verdana"
            }
            Label {
                id: aboutMeArea
                text: aboutMe
                translationY: 60.0
                textStyle.fontFamily: "Verdana"
                textStyle.color: Color.White
            }
        }
        Container {
            background: Color.create("#333333")
            preferredWidth: 728.0
            preferredHeight: 130.0
            translationX: 20.0
            translationY: 880.0
            layout: AbsoluteLayout {
            }
            ImageButton {
                id: linkedin_icon_access
                defaultImageSource: "asset:///images/linkedin_icon_color.png"
                pressedImageSource: "asset:///images/linkedin_icon_bw.png"
                translationX: 0.0
            }
            //                ImageButton {
            //                    defaultImageSource: "asset:///images/button_ok.png"
            //                    translationX: 560.0
            //                    onClicked: {
            //                    }
            //                }
        }
        //        EditControls {
        //Go to the edit page
        //        }
    }
    function newCard() {
        nameField.text = "";
        corporateTitle.text = "";
        emailField.text = "";
        phoneField.text = "";
        addressArea.text = "";
        aboutMeArea.text = "";
    }
    paneProperties: NavigationPaneProperties {
        backButton: ActionItem {
            title: "Cards"
            onTriggered: {
                nav.pop();
                container.editMode = false;
            }
        }
    }
    actions: [
        //Remeber to change: Can't edit cards received
        ActionItem {
            title: "Edit"
            imageSource: "asset:///images/Edit.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                container.editMode = true
            }
        },
        DeleteActionItem {
            
            objectName: "DeleteAction"
            title: "Delete"
            onTriggered: {
                _closer.deleteRecord();
                nav.pop();
                container.editMode = false
            }
        }
    ]
}
