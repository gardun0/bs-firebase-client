[@bs.module "firebase/database"] external enableLogging : (
  ~logger: 'a = ?,
  ~persistent: bool = ?,
  unit
) => 'a = "";

module ServerValue = {
  [@bs.module "firebase/database"]
  [@bs.scope "database"]
  [@bs.scope "ServerValue"]
  [@bs.val]
  external timestamp : string = "TIMESTAMP";
};

module Database = {
  type t;
};

module ReferenceRef = {
  type t;
};

module OnDisconnect = {
  type t;

  [@bs.send] external cancel : (t, ~onComplete: (Js.Nullable.t(Js.t('a)) => unit) = ?) => Js.Promise.t('a) = "";

  [@bs.send] external remove : (t, ~onComplete: (Js.Nullable.t(Js.t('a)) => unit) = ?) => Js.Promise.t('a) = "";

  [@bs.send] external set : (t, 'a, ~onComplete: (Js.Nullable.t(Js.t('a)) => unit) = ?) => Js.Promise.t('a) = "";

  [@bs.send] external setWithPriority : (t,
    ~value : 'a,
    ~priority : 'b,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => unit) = ?,
    unit
  ) => Js.Promise.t('a) = "";

  [@bs.send] external update : (t,
    ~value : 'a => unit,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => unit) = ?,
    unit
  ) => Js.Promise.t('a) = "";
}

module DataSnapshot = {
  type t;

  [@bs.get] external key : t => string = "";

  [@bs.send] external child : (t, string) => t = "";

  [@bs.send] external exists : t => bool = "";

  [@bs.send] external exportVal : t => 'a = "";

  [@bs.send] external forEach : (t, (t) => 'a) => bool = "";

  [@bs.send] external getPriority : t => 'a = "";

  [@bs.send] external hasChild : (t, string) => bool = "";

  [@bs.send] external hasChildren : (t, string) => bool = "";

  [@bs.send] external numChildren : t => int = "";

  [@bs.send] external toJSON : t => Js.Json.t = "";

  [@bs.send] external val_ : t => 'a = "val";
};

module Query = {
  type t;

  [@bs.get] external ref : t => ReferenceRef.t = "";

  [@bs.send] external endAt : (t, ~value: 'a, ~key: 'b = ?, unit) => t = "";
  [@bs.send] external equalTo : (t, ~value: 'a, ~key: 'b = ?, unit) => t = "";
  [@bs.send] external isEqual : (t, t) => bool = "";
  [@bs.send] external limitToFirst : (t, int) => t = "";
  [@bs.send] external limitToLast : (t, int) => t = "";

  [@bs.send] external off : (t,
    ~event : [@bs.string] [
      | [@bs.as "value"] `Value
      | [@bs.as "child_added"] `ChildAdded
      | [@bs.as "child_changed"] `ChildChanged
      | [@bs.as "child_moved"] `ChildMoved
      | [@bs.as "child_removed"] `ChildRemoved
    ] = ?,
    ~callback : (DataSnapshot.t => unit) = ?,
    ~context : Js.t('a) = ?,
    unit
  ) => _ = "";

  [@bs.send] external on : (t,
    ~event : [@bs.string] [
      | [@bs.as "value"] `Value
      | [@bs.as "child_added"] `ChildAdded
      | [@bs.as "child_changed"] `ChildChanged
      | [@bs.as "child_moved"] `ChildMoved
      | [@bs.as "child_removed"] `ChildRemoved
    ],
    ~callback : (DataSnapshot.t, Js.Nullable.t(string)) => unit,
    ~cancelCallbackOrContext : Js.t('a) = ?,
    ~context : Js.t('a) = ?,
    unit
  ) => (DataSnapshot.t => _) = "";

  [@bs.send] external once : (t,
    ~event : [@bs.string] [
      | [@bs.as "value"] `Value
      | [@bs.as "child_added"] `ChildAdded
      | [@bs.as "child_changed"] `ChildChanged
      | [@bs.as "child_moved"] `ChildMoved
      | [@bs.as "child_removed"] `ChildRemoved
    ],
    ~successCallback : (DataSnapshot.t, Js.Nullable.t(string)) => unit,
    ~failureCallbackOrContext : Js.t('a) = ?,
    ~context : Js.t('a) = ?,
    unit
  ) => (DataSnapshot.t => _) = "";

  [@bs.send] external orderByChild : (t, string) => t = "";

  [@bs.send] external orderByKey : t => t = "";

  [@bs.send] external orderByPriority : t => t = "";

  [@bs.send] external orderByValue : t => t = "";

  [@bs.send] external startAt : (t, ~value: 'a, ~key: 'b = ?, unit) => t = "";

  [@bs.send] external toJSON : t => Js.Json.t = "";

  [@bs.send] external toString : t => string = "";
};

module Reference = {
  [@bs.get] external key : ReferenceRef.t => string = "";
  [@bs.get] external parent : ReferenceRef.t => Js.Nullable.t(ReferenceRef.t) = "";
  [@bs.get] external ref : ReferenceRef.t => ReferenceRef.t = "";
  [@bs.get] external root : ReferenceRef.t => string = "";

  [@bs.send] external child : (ReferenceRef.t, string) => ReferenceRef.t = "";
  [@bs.send] external endAt : (ReferenceRef.t, ~value: 'a, ~key: 'b = ?, unit) => Query.t = "";
  [@bs.send] external equalTo : (ReferenceRef.t, ~value: 'a, ~key: 'b = ?, unit) => Query.t = "";
  [@bs.send] external isEqual : (ReferenceRef.t, Query.t) => bool = "";
  [@bs.send] external limitToFirst : (ReferenceRef.t, int) => Query.t = "";
  [@bs.send] external limitToLast : (ReferenceRef.t, int) => Query.t = "";

  [@bs.send] external off : (ReferenceRef.t,
    ~event : [@bs.string] [
      | [@bs.as "value"] `Value
      | [@bs.as "child_added"] `ChildAdded
      | [@bs.as "child_changed"] `ChildChanged
      | [@bs.as "child_moved"] `ChildMoved
      | [@bs.as "child_removed"] `ChildRemoved
    ] = ?,
    ~callback : (DataSnapshot.t => unit) = ?,
    ~context : Js.t('a) = ?,
    unit
  ) => _ = "";

  [@bs.send] external on : (ReferenceRef.t,
    ~event : [@bs.string] [
      | [@bs.as "value"] `Value
      | [@bs.as "child_added"] `ChildAdded
      | [@bs.as "child_changed"] `ChildChanged
      | [@bs.as "child_moved"] `ChildMoved
      | [@bs.as "child_removed"] `ChildRemoved
    ],
    ~callback : (DataSnapshot.t, Js.Nullable.t(string)) => unit,
    ~cancelCallbackOrContext : Js.t('a) = ?,
    ~context : Js.t('a) = ?,
    unit
  ) => (DataSnapshot.t => _) = "";

  [@bs.send] external onDisconnect : ReferenceRef.t => OnDisconnect.t = "";

  [@bs.send] external once : (ReferenceRef.t,
    ~event : [@bs.string] [
      | [@bs.as "value"] `Value
      | [@bs.as "child_added"] `ChildAdded
      | [@bs.as "child_changed"] `ChildChanged
      | [@bs.as "child_moved"] `ChildMoved
      | [@bs.as "child_removed"] `ChildRemoved
    ],
    ~successCallback : (DataSnapshot.t, Js.Nullable.t(string)) => unit,
    ~failureCallbackOrContext : Js.t('a) = ?,
    ~context : Js.t('a) = ?,
    unit
  ) => (DataSnapshot.t => _) = "";

  [@bs.send] external orderByChild : (ReferenceRef.t, string) => Query.t = "";

  [@bs.send] external orderByKey : ReferenceRef.t => Query.t = "";

  [@bs.send] external orderByPriority : ReferenceRef.t => Query.t = "";

  [@bs.send] external orderByValue : ReferenceRef.t => Query.t = "";

  [@bs.send] external push : (ReferenceRef.t,
    ~value : 'a = ?,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => unit) = ?,
    unit
  ) => Js.Promise.t(ReferenceRef.t) = "";

  [@bs.send] external remove : (ReferenceRef.t,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => unit) = ?,
    unit
  ) => Js.Promise.t('a) = "";

  [@bs.send] external set : (ReferenceRef.t,
    ~value : 'a = ?,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => unit) = ?,
    unit
  ) => Js.Promise.t('a) = "";

  [@bs.send] external setPriority : (ReferenceRef.t, 'a, Js.Nullable.t(Js.t('a)) => unit) => Js.Promise.t('a) = "";

  [@bs.send] external setWithPriority : (ReferenceRef.t,
    ~value : 'a,
    ~priority : 'b,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => unit) = ?,
    unit
  ) => Js.Promise.t('a) = "";

  [@bs.send] external startAt : (ReferenceRef.t, ~value: 'a, ~key: 'b = ?, unit) => Query.t = "";

  [@bs.send] external toJSON : ReferenceRef.t => Js.Json.t = "";

  [@bs.send] external toString : ReferenceRef.t => string = "";

  [@bs.send] external transaction : (ReferenceRef.t,
    ~update : 'a => unit,
    ~onComplete : ((Js.Nullable.t(Js.t('a)), bool, Js.Nullable.t(DataSnapshot.t)) => unit) = ?,
    ~applyLocally : bool,
    unit
  ) => Js.Promise.t('a) = "";

  [@bs.send] external update : (ReferenceRef.t,
    ~value : 'a => unit,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => unit) = ?,
    unit
  ) => Js.Promise.t('a) = "";
};

module Make = (App: Firebase_App.App) => {
  [@bs.send] external database : App.t => Database.t = "database";
  let instance = database(App.instance);

  [@bs.get] external app : Database.t => App.t = "";

  [@bs.send] external goOffline : Database.t => _ = "";
  [@bs.send] external goOnline : Database.t => _ = "";

  [@bs.send] external ref : (Database.t, string) => ReferenceRef.t = ""
  [@bs.send] external refUrl : (Database.t, string) => ReferenceRef.t = "refFromUrl"
};