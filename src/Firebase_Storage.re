[%raw "require('firebase/storage')"];

module Storage = {
  type t;
}

module ReferenceRef = {
  type t;
}

module UploadTaskRef = {
  type t;
};

type uploadMetadata = Js.t({
  .
  "cacheControl": Js.Nullable.t(string),
  "contentDisposition": Js.Nullable.t(string),
  "contentEncoding": Js.Nullable.t(string),
  "contentLanguage": Js.Nullable.t(string),
  "contentType": Js.Nullable.t(string),
  "customMetadata": Js.Nullable.t(string),
  "md5Hash": Js.Nullable.t(string)
})

type settableMetadata = Js.t({
  .
  "cacheControl": Js.Nullable.t(string),
  "contentDisposition": Js.Nullable.t(string),
  "contentEncoding": Js.Nullable.t(string),
  "contentLanguage": Js.Nullable.t(string),
  "contentType": Js.Nullable.t(string),
  "customMetadata": Js.Nullable.t(string)
})

type fullMetadata = Js.t({
  .
  "bucket": string,
  "cacheControl": Js.Nullable.t(string),
  "contentDisposition": Js.Nullable.t(string),
  "contentEncoding": Js.Nullable.t(string),
  "contentLanguage": Js.Nullable.t(string),
  "contentType": Js.Nullable.t(string),
  "customMetadata": Js.Nullable.t(string),
  "fullPath": string,
  "generation": string,
  "md5hash": Js.Nullable.t(string),
  "metageneration": string,
  "name": string,
  "size": string,
  "timeCreated": string,
  "updated": string
})

type observer('a) = Js.t({
  .
  "next": 'a,
  "error": Js.Nullable.t('a),
  "complete": Js.Nullable.t('a)
})

module UploadTaskSnapshot = {
  type t;

  [@bs.get] external bytesTransferred : t => float = "";

  [@bs.get] external metadata : t => fullMetadata = "";

  [@bs.get] external ref : t => ReferenceRef.t = "";

  [@bs.get] external state : t => string = "";

  [@bs.get] external task : t => UploadTaskRef.t = "";

  [@bs.get] external totalBytes : t => float = "";
}

module UploadTask = {
  type cancel = unit => unit;

  type callback('a) = (~next : 'a => 'a = ?, ~error: 'a => 'a = ?, ~complete: 'a => 'a = ?, unit) => unit;

  [@bs.get] external snapshot : UploadTaskRef.t => UploadTaskSnapshot.t = "";

  [@bs.send] external cancel : UploadTaskRef.t => bool = "";

  // [@bs.send] external catch : (t, Js.t('a) => 'a) => Js.Promise.t('a) = "";

  [@bs.send] external on : (UploadTaskRef.t,
    ~event : [@bs.string] [
      | [@bs.as "state_changed"] `StateChanged
    ],
    ~next: UploadTaskSnapshot.t => 'a = ?,
    ~error: Js.t('a) => 'a = ?,
    ~complete: unit => 'a = ?,
    unit
  ) => cancel = "";

  [@bs.send] external onWithObserver : (UploadTaskRef.t,
    ~event : [@bs.string] [
      | [@bs.as "state_changed"] `StateChanged
    ],
    ~observer: observer('a) = ?,
    unit
  ) => cancel = "";

  [@bs.send] external onAsCallback : (UploadTaskRef.t,
    [@bs.string] [
      | [@bs.as "state_changed"] `StateChanged
    ]
  ) => callback('a) = "";

  [@bs.send] external pause : UploadTaskRef.t => bool = "";

  [@bs.send] external resume : UploadTaskRef.t => bool = "";
}

module Reference = {
  [@bs.get] external bucket : ReferenceRef.t => string = "";

  [@bs.get] external fullPath : ReferenceRef.t => string = "";

  [@bs.get] external name : ReferenceRef.t => string = "";

  [@bs.get] external parent : ReferenceRef.t => Js.Nullable.t(ReferenceRef.t) = "";

  [@bs.get] external root : ReferenceRef.t => ReferenceRef.t = "";

  [@bs.get] external storage : ReferenceRef.t => Storage.t = "";

  [@bs.send] external child : (ReferenceRef.t, string) => ReferenceRef.t = "";

  [@bs.send] external delete : ReferenceRef.t => Js.Promise.t('a) = "";

  [@bs.send] external getDownloadURL : ReferenceRef.t => Js.Promise.t('a) = "";

  [@bs.send] external getMetadata : ReferenceRef.t => Js.Promise.t('a) = "";

  [@bs.send] external put : (ReferenceRef.t, 'a, ~metadata : uploadMetadata = ?, unit) => UploadTaskRef.t = "";

  [@bs.send] external sendString : (ReferenceRef.t, string, ~format : [@bs.string] [
    | [@bs.as "raw"] `Raw
    | [@bs.as "base64"] `Base64
    | [@bs.as "base64url"] `Base64Url
    | [@ba.as "data_url"] `DataUrl
  ] = ?, ~metadata : uploadMetadata = ?, unit) => UploadTaskRef.t = "";

  [@bs.send] external toString : ReferenceRef.t => string = "";

  [@bs.send] external updateMetadata : (ReferenceRef.t, settableMetadata) => Js.Promise.t('a) = "";
}

module Make = (App :  Firebase_App.App) => {

  [@bs.send] external storage : App.t => Storage.t = "storage";
  let instance = storage(App.instance);

  [@bs.get] external app : Storage.t => App.t = "";

  [@bs.get] external maxOperationRetryTime : Storage.t => int = "";

  [@bs.get] external maxUploadRetryTime : Storage.t => int = "";

  [@bs.send] external ref : (Storage.t, ~path : string = ?, unit) => ReferenceRef.t = "";

  [@bs.send] external refFromURL : (Storage.t, string) => ReferenceRef.t = "";

  [@bs.send] external setMaxOperationRetryTime : (Storage.t, int) => 'a = "";

  [@bs.send] external setMaxUploadRetryTime : (Storage.t, int) => 'a = "";
}
