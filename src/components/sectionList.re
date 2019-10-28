type jsSeparatorProps('item, 'sectionData) =
  ReactNative.VirtualizedSectionList.separatorProps('item, 'sectionData);

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

type separatorProps('item, 'sectionData) = {
  highlighted: bool,
  leadingItem: option('item),
  leadingSection: option(section('item, 'sectionData)),
  section: section('item, 'sectionData),
  trailingItem: option('item),
  trailingSection: option(section('item, 'sectionData)),
};

type renderItem('item, 'sectionData) =
  ReactNative.VirtualizedSectionList.renderItemProps('item, 'sectionData) =>
  React.element;

let jsSectionToSection = jsSection => {
  data: jsSection##data,
  key: jsSection##key,
  /*** We set renderItem to None to avoid an infinite conversion loop */
  renderItem: None,
};

type sections('item, 'sectionData) =
  array(ReactNative.VirtualizedSectionList.section('item, 'sectionData));

let renderItem =
    (reRenderItem: renderBag('item, 'sectionData) => React.element)
    : renderItem('item, 'sectionData) =>
  (
    jsRenderBag:
      ReactNative.VirtualizedSectionList.renderItemProps('item, 'sectionData),
  ) =>
    reRenderItem({
      item: jsRenderBag##item,
      index: jsRenderBag##index,
      section: jsSectionToSection(jsRenderBag##section),
      separators: jsRenderBag##separators,
    });

let section = (~data, ~key=?, ~renderItem=?, ()) => {data, key, renderItem};

let sections = (reSections): sections('item, 'sectionData) =>
  Array.map(
    reSection =>
      {
        "data": reSection.data,
        "key": reSection.key,
        "renderItem": reSection.renderItem->Belt.Option.map(renderItem),
        "ItemSeparatorComponent": None,
        "keyExtractor": None,
        "sectionData": None,
      },
    reSections,
  );

type separatorComponent('item, 'sectionData) =
  jsSeparatorProps('item, 'sectionData) => React.element;

let separatorComponent =
    (
      reSeparatorComponent:
        separatorProps('item, 'sectionData) => React.element,
    )
    : separatorComponent('item, 'sectionData) =>
  (jsSeparatorProps: jsSeparatorProps('item, 'sectionData)) =>
    reSeparatorComponent({
      highlighted: jsSeparatorProps##highlighted,
      leadingItem: jsSeparatorProps##leadingItem,
      leadingSection:
        jsSeparatorProps##leadingSection->Belt.Option.map(jsSectionToSection),
      section: jsSectionToSection(jsSeparatorProps##section),
      trailingItem: jsSeparatorProps##trailingItem,
      trailingSection:
        jsSeparatorProps##trailingSection
        ->Belt.Option.map(jsSectionToSection),
    });

type viewToken('item, 'sectionData) = {
  .
  "item": 'item,
  "key": string,
  "index": Js.undefined(int),
  "isViewable": bool,
  "section": section('item, 'sectionData),
};

type jsRenderAccessory('item, 'sectionData) = {
  .
  "section": ReactNative.VirtualizedSectionList.section('item, 'sectionData),
};

type renderAccessory('item, 'sectionData) = {
  section: section('item, 'sectionData),
};

type renderAccessoryView('item, 'sectionData) =
  jsRenderAccessory('item, 'sectionData) => React.element;

let renderAccessoryView =
    (
      reRenderAccessory: renderAccessory('item, 'sectionData) => React.element,
    )
    : renderAccessoryView('item, 'sectionData) =>
  (jsRenderAccessory: jsRenderAccessory('item, 'sectionData)) =>
    reRenderAccessory({
      section: jsSectionToSection(jsRenderAccessory##section),
    });

[@react.component]
let make =
    (
      ~sections:
         array(
           ReactNative.VirtualizedSectionList.section('item, 'sectionData),
         ),
      ~renderItem:
         ReactNative.VirtualizedSectionList.renderItemCallback(
           'item,
           'sectionData,
         ),
      ~keyExtractor: ('item, int) => string,
      ~itemSeparatorComponent:
         option(separatorComponent('item, 'sectionData))=?,
      ~listEmptyComponent: option(React.element)=?,
      ~listFooterComponent: option(React.element)=?,
      ~listHeaderComponent: option(React.element)=?,
      ~sectionSeparatorComponent:
         option(separatorComponent('item, 'sectionData))=?,
      ~inverted: option(bool)=?,
      ~extraData: option('extraData)=?,
      ~initialNumToRender: option(int)=?,
      ~onEndReached:
         option(ReactNative.VirtualizedList.onEndReachedParams => unit)=?,
      ~onEndReachedThreshold: option(float)=?,
      ~onViewableItemsChanged:
         option(
           ReactNative.VirtualizedList.viewableItemsChanged('item) => unit,
         )=?,
      ~onRefresh: option(unit => unit)=?,
      ~refreshing: option(bool)=?,
      ~renderSectionHeader:
         option(
           ReactNative.VirtualizedSectionList.renderSectionHeaderCallback(
             'item,
             'sectionData,
           ),
         )=?,
      ~renderSectionFooter:
         option(
           ReactNative.VirtualizedSectionList.renderSectionHeaderCallback(
             'item,
             'sectionData,
           ),
         )=?,
      ~stickySectionHeadersEnabled: option(bool)=?,
      ~keyboardDismissMode: option([ | `none | `interactive | `onDrag])=?,
      ~keyboardShouldPersistTaps: option([ | `always | `never | `handled])=?,
      ~showsHorizontalScrollIndicator: option(bool)=?,
      ~showsVerticalScrollIndicator: option(bool)=?,
      ~getItemLayout:
         option(
           (array('item), int) => ReactNative.VirtualizedList.itemLayout,
         )=?,
      _,
    ) =>
  <ReactNative.SectionList
    sections
    renderItem
    keyExtractor
    _ItemSeparatorComponent=?itemSeparatorComponent
    _ListEmptyComponent=?{listEmptyComponent->Belt.Option.map((x, ()) => x)}
    _ListFooterComponent=?{listFooterComponent->Belt.Option.map((x, ()) => x)}
    _ListHeaderComponent=?{listHeaderComponent->Belt.Option.map((x, ()) => x)}
    _SectionSeparatorComponent=?sectionSeparatorComponent
    ?inverted
    ?extraData
    ?initialNumToRender
    ?onEndReached
    ?onEndReachedThreshold
    ?onRefresh
    ?onViewableItemsChanged
    ?refreshing
    ?renderSectionHeader
    ?renderSectionFooter
    ?stickySectionHeadersEnabled
    ?keyboardDismissMode
    ?keyboardShouldPersistTaps
    ?showsHorizontalScrollIndicator
    ?showsVerticalScrollIndicator
    getItemLayout=?{
      getItemLayout->Belt.Option.map((f, data, index) => f(data, index))
    }
  />;
