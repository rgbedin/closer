import bb.cascades 1.0

Container {
    id: cardContainer
    
    layout: DockLayout {
    }
    
    // A colored Container is used to highlight the item on selection.
    Container {
        id: highlight
        background: Color.Black
        opacity: 0.0
        horizontalAlignment: HorizontalAlignment.Fill
        verticalAlignment: VerticalAlignment.Fill        
    }
    
    ImageView {
        
        // When using ListItems its best to use imageSources of content-type (relative path) 
        // rather then asset-type (prefixed asset:///). This is because asset-type images are loaded 
        // immediately and can affect the scroll performance of the list (see the models/stamps.xml 
        // to see what an imageSource of content type typically looks like).
        imageSource: ListItemData.backGroundImageAddress
        scalingMethod: ScalingMethod.AspectFit
        verticalAlignment: VerticalAlignment.Center
        horizontalAlignment: HorizontalAlignment.Center
    }

    // Both the activation and selection of an item has the same visual appearance, we alter the opacity of the item.
//    function setHighlight (highlighted) {
//        if (highlighted) {
//            highlight.opacity = 0.2;
//        } else {
//            highlight.opacity = 0.0;
//        }
//    }
//
//    // Signal handler for ListItem activation
//    ListItem.onActivationChanged: {
//        setHighlight (ListItem.active);
//    }
//
//    // Signal handler for ListItem selection
//    ListItem.onSelectionChanged: {
//        setHighlight (ListItem.selected);
//    }
}
