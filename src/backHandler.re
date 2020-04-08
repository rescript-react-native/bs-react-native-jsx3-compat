[@bs.scope "BackHandler"] [@bs.module "react-native"]
external exitApp: unit => unit = "exitApp";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external addEventListener: (string, unit => bool) => unit = "addEventListener";

[@bs.scope "BackHandler"] [@bs.module "react-native"]
external removeEventListener: (string, unit => bool) => unit =
  "removeEventListener";
