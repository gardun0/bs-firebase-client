module ServerValue = {
  [@bs.module "firebase/database"]
  [@bs.scope "database"]
  [@bs.scope "ServerValue"]
  [@bs.val]
  external timestamp : string = "TIMESTAMP";
};

module OnDisconnect = {
  type t;

  [@bs.send] external cancel : (t, ~onComplete: (Js.Nullable.t(Js.t('a)) => _) = ?) => Js.Promise.t('a) = "";

  [@bs.send] external remove : (t, ~onComplete: (Js.Nullable.t(Js.t('a)) => _) = ?) => Js.Promise.t('a) = "";

  [@bs.send] external set : (t, 'a, ~onComplete: (Js.Nullable.t(Js.t('a)) => _) = ?) => Js.Promise.t('a) = "";

  [@bs.send] external setWithPriority : (t,
    ~value : 'a,
    ~priority : 'b,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => _) = ?,
    unit
  ) => Js.Promise.t('a) = "";

  [@bs.send] external update : (t,
    ~value : 'a => unit,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => _) = ?,
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
    ~callback : (DataSnapshot.t => _) = ?,
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
    ~callback : (DataSnapshot.t, Js.Nullable.t(string)) => _,
    ~cancelCallbackOrContext : Js.t('a) = ?,
    ~context : Js.t('a) = ?
  ) => (DataSnapshot.t => _) = "";

  [@bs.send] external once : (t,
    ~event : [@bs.string] [
      | [@bs.as "value"] `Value
      | [@bs.as "child_added"] `ChildAdded
      | [@bs.as "child_changed"] `ChildChanged
      | [@bs.as "child_moved"] `ChildMoved
      | [@bs.as "child_removed"] `ChildRemoved
    ],
    ~successCallback : (DataSnapshot.t, Js.Nullable.t(string)) => _,
    ~failureCallbackOrContext : Js.t('a) = ?,
    ~context : Js.t('a) = ?
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
  type t;

  [@bs.get] external key : t => string = "";
  [@bs.get] external parent : t => string = "";
  [@bs.get] external ref : t => t = "";
  [@bs.get] external root : t => string = "";

  [@bs.send] external child : (t, string) => t = "";
  [@bs.send] external endAt : (t, ~value: 'a, ~key: 'b = ?, unit) => Query.t = "";
  [@bs.send] external equalTo : (t, ~value: 'a, ~key: 'b = ?, unit) => Query.t = "";
  [@bs.send] external isEqual : (t, Query.t) => bool = "";
  [@bs.send] external limitToFirst : (t, int) => Query.t = "";
  [@bs.send] external limitToLast : (t, int) => Query.t = "";

  [@bs.send] external off : (t,
    ~event : [@bs.string] [
      | [@bs.as "value"] `Value
      | [@bs.as "child_added"] `ChildAdded
      | [@bs.as "child_changed"] `ChildChanged
      | [@bs.as "child_moved"] `ChildMoved
      | [@bs.as "child_removed"] `ChildRemoved
    ] = ?,
    ~callback : (DataSnapshot.t => _) = ?,
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
    ~callback : (DataSnapshot.t, Js.Nullable.t(string)) => _,
    ~cancelCallbackOrContext : Js.t('a) = ?,
    ~context : Js.t('a) = ?
  ) => (DataSnapshot.t => _) = "";

  [@bs.send] external onDisconnect : unit => OnDisconnect.t = "";

  [@bs.send] external once : (t,
    ~event : [@bs.string] [
      | [@bs.as "value"] `Value
      | [@bs.as "child_added"] `ChildAdded
      | [@bs.as "child_changed"] `ChildChanged
      | [@bs.as "child_moved"] `ChildMoved
      | [@bs.as "child_removed"] `ChildRemoved
    ],
    ~successCallback : (DataSnapshot.t, Js.Nullable.t(string)) => _,
    ~failureCallbackOrContext : Js.t('a) = ?,
    ~context : Js.t('a) = ?
  ) => (DataSnapshot.t => _) = "";

  [@bs.send] external orderByChild : (t, string) => Query.t = "";

  [@bs.send] external orderByKey : t => Query.t = "";

  [@bs.send] external orderByPriority : t => Query.t = "";

  [@bs.send] external orderByValue : t => Query.t = "";

  [@bs.send] external push : (t,
    ~value : 'a = ?,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => _) = ?,
    unit
  ) => Js.Promise.t(t) = "";

  [@bs.send] external remove : (t,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => _) = ?,
    unit
  ) => Js.Promise.t('a) = "";

  [@bs.send] external set : (t,
    ~value : 'a = ?,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => _) = ?,
    unit
  ) => Js.Promise.t('a) = "";

  [@bs.send] external setPriority : ('a, Js.Nullable.t(Js.t('a)) => _) => Js.Promise.t('a) = "";

  [@bs.send] external setWithPriority : (t,
    ~value : 'a,
    ~priority : 'b,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => _) = ?,
    unit
  ) => Js.Promise.t('a) = "";

  [@bs.send] external startAt : (t, ~value: 'a, ~key: 'b = ?, unit) => Query.t = "";

  [@bs.send] external toJSON : t => Js.Json.t = "";

  [@bs.send] external toString : t => string = "";

  [@bs.send] external transaction : (t,
    ~update : 'a => unit,
    ~onComplete : ((Js.Nullable.t(Js.t('a)), bool, Js.Nullable.t(DataSnapshot.t)) => _) = ?,
    ~applyLocally : bool,
    unit
  ) => Js.Promise.t('a) = "";

  [@bs.send] external update : (t,
    ~value : 'a => unit,
    ~onComplete : (Js.Nullable.t(Js.t('a)) => _) = ?,
    unit
  ) => Js.Promise.t('a) = "";
};

module Make = (App: Firebase_App.App) => {
  type t;

  [@bs.send] external database : App.t => t = "database";
  let instance = database(App.instance);

  [@bs.get] external app : t => _ = "";

  [@bs.send] external goOffline : t => _ = "";
  [@bs.send] external goOnline : t => _ = "";

  [@bs.send] external ref : (t, string) => Reference.t = ""
  [@bs.send] external refUrl : (t, string) => Reference.t = "refFromUrl"
};