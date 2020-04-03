type t;

module NativeEvent = {
  type t = ReactNative.Event.pressEvent;
  [@bs.get]
  external changedTouches: t => array(Js.t({..})) = "changedTouches";
  [@bs.get] external identifier: t => int = "identifier";
  [@bs.get] external locationX: t => float = "locationX";
  [@bs.get] external locationY: t => float = "locationY";
  [@bs.get] external pageX: t => float = "pageX";
  [@bs.get] external pageY: t => float = "pageY";
  [@bs.get] external target: t => Js.t({..}) = "target";
  [@bs.get] external touches: t => array(Js.t({..})) = "touches";
  [@bs.get] external timestamp: t => int = "timestamp";
  [@bs.get] external data: t => string = "data";
};

/*
 fixme rename NativeEvent to NativePressEvent when necessary
 see https://github.com/facebook/react-native/blob/master/Libraries/Types/CoreEventTypes.js
 */
module NativePressEvent = NativeEvent;

module NativeLayoutEvent = {
  type t = ReactNative.Event.layoutEvent;
  type layout = {
    x: float,
    y: float,
    width: float,
    height: float,
  };
  [@bs.get] external _layout: t => Js.t('a) = "nativeEvent";
  let layout = (t: t) => {
    let l = _layout(t)##layout;
    {x: l##x, y: l##y, width: l##width, height: l##height};
  };
};

module NativeScrollEvent = {
  type t = ReactNative.Event.scrollEvent;
  type point = {
    x: float,
    y: float,
  };
  type size = {
    width: float,
    height: float,
  };
  type contentInset = {
    bottom: float,
    top: float,
    left: float,
    right: float,
  };
  [@bs.get] external _nativeEvent: t => Js.t('a) = "nativeEvent";
  let contentOffset = (t: t) => {
    let co = _nativeEvent(t)##contentOffset;
    {x: co##x, y: co##y};
  };
  let contentSize = (t: t) => {
    let cs = _nativeEvent(t)##contentSize;
    {width: cs##width, height: cs##height};
  };
  let layoutMeasurement = (t: t) => {
    let lm = _nativeEvent(t)##layoutMeasurement;
    {width: lm##width, height: lm##height};
  };
  let contentInset = (t: t) => {
    let ci = _nativeEvent(t)##contentInset;
    {bottom: ci##bottom, top: ci##top, left: ci##left, right: ci##right};
  };
};

[@bs.get] external nativeEvent: t => NativeEvent.t = "nativeEvent";

[@bs.get] external nativeLayoutEvent: t => NativeLayoutEvent.t = "nativeEvent";

[@bs.get] external nativeScrollEvent: t => NativeScrollEvent.t = "nativeEvent";
