type geolactionConfig;

type currentPositionConfig;

type watchPositionConfig;

type watchId = int;

type position = {
  .
  "coords": coords,
  "timestamp": float,
}
and coords = {
  .
  "speed": int,
  "longitude": float,
  "latitude": float,
  "accuracy": int,
  "heading": int,
};

type error = {
  .
  "code": int,
  "message": string,
};

[@bs.obj]
external makeGeolocationConfig:
  (~skipPermissionRequests: bool=?) => geolactionConfig;

[@bs.obj]
external makeCurrentPositionConfig:
  (~timeout: int=?, ~maximumAge: int=?, ~enableHighAccuracy: bool=?) =>
  currentPositionConfig;

[@bs.obj]
external makeWatchPositionConfig:
  (
    ~timeout: int=?,
    ~maximumAge: int=?,
    ~enableHighAccuracy: bool=?,
    ~distanceFilter: int=?,
    ~useSignificantChanges: bool=?
  ) =>
  watchPositionConfig;

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external setRNConfiguration: geolactionConfig => unit = "setRNConfiguration";

let setRNConfiguration = (~skipPermissionRequests=?, ()) =>
  setRNConfiguration(makeGeolocationConfig(~skipPermissionRequests?));

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external requestAuthorization: unit => unit = "requestAuthorization";

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external stopObserving: unit => unit = "stopObserving";

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external getCurrentPosition:
  (position => unit, error => unit, currentPositionConfig) => unit =
  "getCurrentPosition";

let getCurrentPosition =
    (~timeout=?, ~maximumAge=?, ~enableHighAccuracy=?, success, error) =>
  getCurrentPosition(
    success,
    error,
    makeCurrentPositionConfig(~timeout?, ~maximumAge?, ~enableHighAccuracy?),
  );

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external watchPosition:
  (position => unit, error => unit, watchPositionConfig) => watchId =
  "watchPosition";

let watchPosition =
    (
      ~timeout=?,
      ~maximumAge=?,
      ~enableHighAccuracy=?,
      ~distanceFilter=?,
      ~useSignificantChanges=?,
      success,
      error,
    ) =>
  watchPosition(
    success,
    error,
    makeWatchPositionConfig(
      ~timeout?,
      ~maximumAge?,
      ~enableHighAccuracy?,
      ~distanceFilter?,
      ~useSignificantChanges?,
    ),
  );

[@bs.val] [@bs.scope ("navigator", "geolocation")]
external clearWatch: watchId => unit = "clearWatch";
