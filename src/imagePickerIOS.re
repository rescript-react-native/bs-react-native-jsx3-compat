[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external canUseCamera: (unit => unit) => unit = "canUseCamera";

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external canRecordVideos: (unit => unit) => unit = "canRecordVideos";

type error = {
  .
  "code": int,
  "message": string,
};

type cameraDialogConfig = {. "videoMode": bool};

[@bs.obj]
external makeCameraDialogConfig: (~videoMode: bool) => cameraDialogConfig;

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external openCameraDialog:
  (cameraDialogConfig, unit => unit, error => unit) => unit =
  "openCameraDialog";

let openCameraDialog = (~videoMode, ~onSuccess, ~onError) =>
  openCameraDialog(makeCameraDialogConfig(~videoMode), onSuccess, onError);

type selectDialogConfig = {
  .
  "showImages": bool,
  "showVideos": bool,
};

[@bs.obj]
external makeSelectDialogConfig:
  (~showImages: bool, ~showVideos: bool) => selectDialogConfig;

[@bs.module "react-native"] [@bs.scope "ImagePickerIOS"]
external openSelectDialog:
  (selectDialogConfig, string => unit, error => unit) => unit =
  "openSelectDialog";

let openSelectDialog = (~showImages, ~showVideos, ~onSuccess, ~onError) =>
  openSelectDialog(
    makeSelectDialogConfig(~showImages, ~showVideos),
    onSuccess,
    onError,
  );
