/**
  A performant interface for rendering sectioned lists, supporting the most handy features:
  You can read more on [SectionList] component usage in official docs: {{:https://facebook.github.io/react-native/docs/sectionlist}}

  {3 Props}
  {4 sections}
  The actual data to render, akin to the data prop in FlatList.
  {[
    ~sections: sections('item),
  ]}
 reference:
  {[
    type renderBag('item) = {
      item: 'item,
      index: int,
      section: section('item),
      separators: {
        .
        "highlight": unit => unit,
        "unhighlight": unit => unit,
      },
    }
  ]}
  */

type renderBag('item, 'sectionData) = {
  item: 'item,
  index: int,
  section: section('item, 'sectionData),
  separators: {
    .
    "highlight": unit => unit,
    "unhighlight": unit => unit,
  },
}
and section('item, 'sectionData) = {
  data: array('item),
  key: option(string),
  renderItem: option(renderBag('item, 'sectionData) => React.element),
};

let section:
  (
    ~data: array('item),
    ~key: string=?,
    ~renderItem: renderBag('item, 'sectionData) => React.element=?,
    unit
  ) =>
  section('item, 'sectionData);

type sections('item, 'sectionData);

/**
{4 renderItem}
  {[
    ~renderItem: renderItem('item),
  ]}
*/

let sections:
  array(section('item, 'sectionData)) => sections('item, 'sectionData);

type renderItem('item, 'sectionData);

/**
  {4 keyExtractor}
  {[
    ~keyExtractor: ('item, int) => string,
  ]}
  {4 itemSeparatorComponent}
  {[
    ~itemSeparatorComponent: separatorComponent('item)=?,
  ]}
  reference:
*/

let renderItem:
  (renderBag('item, 'sectionData) => React.element) =>
  renderItem('item, 'sectionData);

type separatorProps('item, 'sectionData) = {
  highlighted: bool,
  leadingItem: option('item),
  leadingSection: option(section('item, 'sectionData)),
  section: section('item, 'sectionData),
  trailingItem: option('item),
  trailingSection: option(section('item, 'sectionData)),
};

type separatorComponent('item, 'sectionData);

/**
  {4 listEmptyComponent}
  {[
    ~listEmptyComponent: unit => React.element=?,
  ]}
  {4 listFooterComponent}
  {[
    ~listFooterComponent: React.element=?,
  ]}
  {4 listHeaderComponent}
  {[
    ~listHeaderComponent: React.element=?,
  ]}
  {4 sectionSeparatorComponent}
  {[
    ~sectionSeparatorComponent: separatorComponent('item)=?,
  ]}
  {4 inverted}
  {[
    ~inverted: bool=?,
  ]}
  {4 extraData}
  {[
    ~extraData: 'extraData=?,
  ]}
  {4 initialNumToRender}
  {[
    ~initialNumToRender: int=?,
  ]}
  {4 onEndReached}
  {[
    ~onEndReached: {
      . "distanceFromEnd": float
    } => unit=?,
  ]}
  {4 onEndReachedThreshold}
  {[
    ~onEndReachedThreshold: float=?,
  ]}
  {4 onViewableItemsChanged}
  {[
    onViewableItemsChanged: {
      .
      "changed": array(viewToken('item)),
      "viewableItems": array(viewToken('item)),
    }=?
  ]}
  reference:
  {[
    type viewToken('item) = {
      .
      "index": Js.undefined(int),
      "isViewable": bool,
      "item": 'item,
      "key": string,
      "section": section('item),
    };
  ]}
   */

let separatorComponent:
  (separatorProps('item, 'sectionData) => React.element) =>
  separatorComponent('item, 'sectionData);

type viewToken('item, 'sectionData) = {
  .
  "index": Js.undefined(int),
  "isViewable": bool,
  "item": 'item,
  "key": string,
  "section": section('item, 'sectionData),
};

/**
{4 onRefresh}
{[
  onRefresh: unit => unit=?
]}
{4 refreshing}
{[
  refreshing: bool=?
]}
{4 renderSectionHeaader}
{[
  renderSectionHeader: renderAccessoryView('item)=?
]}
reference:
{[
  type renderAccessory('item) = {
    section: section('item),
  };
]}
 */

type renderAccessory('item, 'sectionData) = {
  section: section('item, 'sectionData),
};

type renderAccessoryView('item, 'sectionData);

/**
  {4 renderSectionFooter}
  {[
    ~renderSectionFooter: renderAccessoryView('item)=?,
  ]}
  {4 stickySectionHeadersEnabled}
  {[
    ~stickySectionHeadersEnabled: bool=?,
  ]}
  {4 keyboardDismissMode}
  {[
    keyboardDismissMode: [
      | `none
      | `interactive
      | `onDrag
    ]=?
  ]}
  {4 keyboardShouldPersistTaps}
  {[
    keyboardShouldPersistTaps: [
      | `always
      | `never
      | `handled
    ]=?
  ]}
  {4 showsHorizontalScrollIndicator}
  {[
    ~showsHorizontalScrollIndicator: bool=?,
  ]}
  {4 showsVerticalScrollIndicator}
  {[
    ~showsVerticalScrollIndicator: bool=?,
  ]}
  {4 getItemLayout}
  {[
    ~getItemLayout: (option(array('item)), int) => {
      .
      "length": int,
      "offset": int,
      "index": int,
    }
      =?,
  ]}
*/

let renderAccessoryView:
  (renderAccessory('item, 'sectionData) => React.element) =>
  renderAccessoryView('item, 'sectionData);

[@react.component]
let make:
  (
    ~sections: array(
                 ReactNative.VirtualizedSectionList.section(
                   'item,
                   'sectionData,
                 ),
               ),
    ~renderItem: ReactNative.VirtualizedSectionList.renderItemCallback(
                   'item,
                   'sectionData,
                 ),
    ~keyExtractor: ('item, int) => string,
    ~itemSeparatorComponent: separatorComponent('item, 'sectionData)=?,
    ~listEmptyComponent: React.element=?,
    ~listFooterComponent: React.element=?,
    ~listHeaderComponent: React.element=?,
    ~sectionSeparatorComponent: separatorComponent('item, 'sectionData)=?,
    ~inverted: bool=?,
    ~extraData: 'extraData=?,
    ~initialNumToRender: int=?,
    ~onEndReached: ReactNative.VirtualizedList.onEndReachedParams => unit=?,
    ~onEndReachedThreshold: float=?,
    ~onViewableItemsChanged: ReactNative.VirtualizedList.viewableItemsChanged(
                               'item,
                             ) =>
                             unit
                               =?,
    ~onRefresh: unit => unit=?,
    ~refreshing: bool=?,
    ~renderSectionHeader: ReactNative.VirtualizedSectionList.renderSectionHeaderCallback(
                            'item,
                            'sectionData,
                          )
                            =?,
    ~renderSectionFooter: ReactNative.VirtualizedSectionList.renderSectionHeaderCallback(
                            'item,
                            'sectionData,
                          )
                            =?,
    ~stickySectionHeadersEnabled: bool=?,
    ~keyboardDismissMode: [ | `none | `interactive | `onDrag]=?,
    ~keyboardShouldPersistTaps: [ | `always | `never | `handled]=?,
    ~showsHorizontalScrollIndicator: bool=?,
    ~showsVerticalScrollIndicator: bool=?,
    ~getItemLayout: (array('item), int) =>
                    ReactNative.VirtualizedList.itemLayout
                      =?,
    unit
  ) =>
  React.element;
