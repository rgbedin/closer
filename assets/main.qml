import bb.cascades 1.0

NavigationPane {
    id: nav
    property variant contentView
    property bool addShown: false
    Page {
        id: cardsReceivedListPage
        Container {
            ListView {
                id: cardsReceivedList
                objectName: "cardsReceivedList"
                layout: StackListLayout {
                    headerMode: ListHeaderMode.Sticky
                }
                dataModel: cardsModel
                listItemComponents: [
                    ListItemComponent {
                        type: "item"
                        StandardListItem {
                            imageSpaceReserved: false
                            title: {
                                ListItemData.company + " - " + ListItemData.corporateTitle;
                            }
                        }
                    }
                //                    ,
                //                    ListItemComponent {
                //                        type: "header"
                //                        Header {
                //                            title: ListItemData
                //                        }
                //                    }
                ]
                onTriggered: {
                    select(indexPath);
                    var chosenItem = dataModel.data(indexPath);
                    
                    if (chosenItem.myCard == "1") {
                        
                        var page = cardPageEdit.createObject();
                        page.company = chosenItem.company;
                        page.name = chosenItem.name;
                        page.corporateTitle = chosenItem.corporateTitle;
                        page.email = chosenItem.email;
                        page.phone = chosenItem.phone;
                        page.address = chosenItem.address;
                        page.aboutMe = chosenItem.aboutMe;
                        //                    page.linkedinProfiles = chosenItem.linkedinProfiles;
                        nav.push(page); //nav.push(page);
                    } else {
                        var page = cardPageDefinition.createObject();
                        page.company = chosenItem.company;
                        page.name = chosenItem.name;
                        page.corporateTitle = chosenItem.corporateTitle;
                        page.email = chosenItem.email;
                        page.phone = chosenItem.phone;
                        page.address = chosenItem.address;
                        page.aboutMe = chosenItem.aboutMe;
                        //                    page.linkedinProfiles = chosenItem.linkedinProfiles;
                        nav.push(page); //nav.push(page);
                    }
                }
                onSelectionChanged: {
                    nav.popAndDelete();
                }
                attachedObjects: [
                    GroupDataModel {
                        id: cardsModel
                        objectName: "cardsModel"
                        grouping: ItemGrouping.ByFirstChar
                        sortingKeys: [
                            "company",
                            "corporateTitle"
                        ]
                        //                        //TODO Add here using NFC.
                        onItemAdded: {
                            if (addShown) {
                                if (nav.top == cardsReceivedListPage) {
                                    cardsReceivedList.clearSelection();
                                    cardsReceivedList.select(indexPath);
                                    cardsReceivedList.scrollToItem(indexPath, ScrollAnimation.Default);
                                    var page = quotePageDefinition.createObject();
                                    nav.push(page);
                                }
                            }
                        }

                        //                        //I didn't uderstand
                        onItemRemoved: {
                            //                            load();
                            nav.popAndDelete();

                            //                            var lastIndexPath = last();
                            //                            if (lastIndexPath[0] == undefined) {
                            //                                if (nav.top != cardsReceivedListPage) {
                            //                                    nav.popAndDelete();
                            //                                }
                            //                            }
                        }
                        //                        //We don't update other people cards, but could be useful to update ours.
                        onItemUpdated: {
                            var chosenItem = data(indexPath);
                            contentView = chosenItem;
                        }
                    }
                ] // End of AttachedObjects
            } // End of ListView
        } // End of Container

        //TODO Add here using NFC.
        actions: [
            ActionItem {
                title: "Create New Card    "
                imageSource: "asset:///images/add.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                onTriggered: {
                    createCard.open();
                    nav.addShown = true;
                }
            }
        ] // end of attachedObjects
        attachedObjects: [
            Sheet {
                id: createCard
                BusinessCardCreator {
                    id: cardPage
                    onBusinessCardCreatorClose: {
                        createCard.close();
                    }
                }
                onClosed: {
                    //cardPage.newQuote();
                }
            },
            ComponentDefinition {
                id: cardPageDefinition
                source: "CardPage.qml"
            },
            ComponentDefinition {
                id: cardPageEdit
                source: "BusinessCardEditor.qml"
            }
        ] // end of attachedObjects
    } // End of Page
    onTopChanged: {
        if (page == cardsReceivedListPage) {
            cardsReceivedList.clearSelection();
        }
    }
    onPopTransitionEnded: {
        page.destroy();
    }
}
