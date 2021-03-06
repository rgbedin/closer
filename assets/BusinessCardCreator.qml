import bb.cascades 1.0

Page {
    id: cardCreator
    property string company: ""
    property string name: ""
    property string corporateTitle: ""
    property string email: ""
    property string phone: ""
    property string address: ""
    property string aboutMe: ""
    property bool editMode: false
    signal businessCardCreatorClose()
    titleBar: TitleBar {
        id: addBar
        title: "Add"
        visibility: ChromeVisibility.Visible
        dismissAction: ActionItem {
            title: "Cancel"
            onTriggered: {
                cardCreator.businessCardCreatorClose()
            }
        }
        acceptAction: ActionItem {
            title: "Save"
            //            enabled: false
            onTriggered: {
                //company varchar(30), name varchar(30), corporateTitle varchar(30), email varchar(60), phone varchar(30), address varchar(90), aboutMe varchar(120), linkedinProfile varchar(120));
                _closer.addNewRecord(companyField.text, nameField.text, corporateTitleField.text, emailField.text, phoneField.text, addressArea.text, aboutMeArea.text, "");
                cardCreator.businessCardCreatorClose();
                company: ""
                name: ""
                corporateTitle: ""
                email: ""
                phone: ""
                address: ""
                aboutMe: ""
            }
        }
    } // TitleBar
    Container {
        id: container
        layout: AbsoluteLayout {
        }
        background: Color.create("#333333")
        preferredWidth: 200.0
        Container {
            background: Color.create("#333333")
            preferredWidth: 728.0
            preferredHeight: 140.0
            translationX: 20.0
            layout: DockLayout {
            }
            TextField {
                id: companyField
                hintText: "Company"
                text: company
                inputMode: TextFieldInputMode.Text
                textStyle.fontSize: FontSize.XLarge
                textStyle.fontFamily: "Verdana"
                textStyle.textAlign: TextAlign.Center
                backgroundVisible: false
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                textStyle.color: Color.White
                //                enabled: false
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
                layout: AbsoluteLayout {
                }
                TextField {
                    id: nameField
                    translationX: 0.0
                    translationY: 120.0
                    hintText: "Name"
                    inputMode: TextFieldInputMode.Text
                    textStyle.fontSize: FontSize.Large
                    textStyle.fontFamily: "Verdana"
                    textStyle.textAlign: TextAlign.Center
                    backgroundVisible: false
                }
                TextField {
                    id: corporateTitleField
                    translationX: 0.0
                    translationY: 200.0
                    hintText: "Corporate Title"
                    inputMode: TextFieldInputMode.Text
                    textStyle.fontSize: FontSize.PercentageValue
                    textStyle.fontFamily: "Verdana"
                    textStyle.textAlign: TextAlign.Center
                    backgroundVisible: false
                }
            }
            Container {
                background: Color.create("#FFFFFF")
                preferredWidth: 384.0
                preferredHeight: 400.0
                translationX: 344.0
                translationY: 0.0
                layout: AbsoluteLayout {
                }
                TextField {
                    id: emailField
                    translationX: 0.0
                    translationY: 20.0
                    hintText: "e-mail"
                    inputMode: TextFieldInputMode.EmailAddress
                    textStyle.fontSize: FontSize.PointValue
                    textStyle.fontFamily: "Verdana"
                    textStyle.textAlign: TextAlign.Center
                    backgroundVisible: false
                }
                TextField {
                    id: phoneField
                    translationX: 0.0
                    translationY: 120.0
                    hintText: "phone"
                    inputMode: TextFieldInputMode.PhoneNumber
                    textStyle.fontSize: FontSize.PointValue
                    textStyle.fontFamily: "Verdana"
                    textStyle.textAlign: TextAlign.Center
                    backgroundVisible: false
                }
                TextArea {
                    id: addressArea
                    translationX: 0.0
                    translationY: 220.0
                    hintText: "address"
                    inputMode: TextFieldInputMode.Text
                    textStyle.fontSize: FontSize.PointValue
                    textStyle.fontFamily: "Verdana"
                    textStyle.textAlign: TextAlign.Center
                    backgroundVisible: false
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
                text: "About me"
                translationX: 280.0
                textStyle.color: Color.White
                textStyle.fontFamily: "Verdana"
            }
            TextArea {
                id: aboutMeArea
                text: ""
                translationY: 60.0
                hintText: "I am..."
                textStyle.fontFamily: "Verdana"
                backgroundVisible: false
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
                id: linkedin_icon
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
    }
}
