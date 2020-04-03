type error;

type base64Image = string;

[@bs.module "react-native"] [@bs.scope "ImageStore"]
external hasImageForTag: (string, bool => unit) => unit = "hasImageForTag";

[@bs.module "react-native"] [@bs.scope "ImageStore"]
external removeImageForTag: string => unit = "removeImageForTag";

[@bs.module "react-native"] [@bs.scope "ImageStore"]
external addImageFromBase64:
  (base64Image, string => unit, error => unit) => unit =
  "addImageFromBase64";

[@bs.module "react-native"] [@bs.scope "ImageStore"]
external getBase64ForTag: (string, base64Image => unit, error => unit) => unit =
  "getBase64ForTag";
