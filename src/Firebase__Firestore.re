[@bs.module "firebase/firestore"] external cacheSizeUnlimited : float = "CACHE_SIZE_UNLIMITED";

[@bs.module "firebase/firestore"] external setLogLevel : ([@bs.string] [
  | [@bs.as "debug"] `Debug
  | [@bs.as "error"] `Error
  | [@bs.as "silent"] `Silent
]) => _ = "";

module Firestore = {
  type t;
};

module CollectionReference = {
  type t;
};

module DocumentReference = {
  type t;
};

type persistenceSettings = Js.t({
  .
  "experimentalTabSynchronization": bool
});

type firebaseSettings = Js.t({
  .
  "cacheSizeBytes": int,
  "host": string,
  "ssl": bool,
  "timestampsInSnapshots": bool
});

type snapshotSettings = Js.t({
  .
  "serverTimestamps": string
});

type snapshotListenSettings = Js.t({
  .
  "includeMetadataChanges": bool
});

type setSettings = Js.t({
  .
  "merge": bool,
  "mergeFields": string
})

type getSettings = Js.t({
  .
  "source": string
})

module SnapshotMetadata = {
  type t;

  [@bs.get] external fromCache : t => bool = "";

  [@bs.get] external hasPendingWrites : t => bool = "";

  [@bs.send] external isEqual : (t, t) => bool = "";
};

module DocumentSnapshot = {
  type t;

  [@bs.get] external exists : t => bool = "";

  [@bs.get] external id : t => string = "";

  [@bs.get] external metadata : t => SnapshotMetadata.t = "";

  [@bs.get] external ref : t => DocumentReference.t = "";

  [@bs.send] external data : (t, snapshotSettings) => Js.Nullable.t(Js.t('a)) = "";

  [@bs.send] external get : (t, string, ~options:snapshotSettings) => 'a = "";

  [@bs.send] external isEqual : (t, t) => bool = "";
};

module Document = {
  type observer('a) = Js.t('a);

  type cancel = unit => unit;

  [@bs.get] external firestore : DocumentReference.t => Firestore.t = "";

  [@bs.get] external id : DocumentReference.t => string = "";

  [@bs.get] external parent : DocumentReference.t => CollectionReference.t = "";

  [@bs.get] external path : DocumentReference.t => string = "";

  [@bs.send] external collection : (DocumentReference.t, string) => CollectionReference.t = "";

  [@bs.send] external delete : DocumentReference.t => Js.Promise.t(_) = "";

  [@bs.send] external get : (DocumentReference.t, getSettings) => Js.Promise.t(DocumentSnapshot.t) = "";

  [@bs.send] external isEqual : (DocumentReference.t, DocumentReference.t) => bool = "";

  [@bs.send] external onSnapshot : (DocumentReference.t, observer('a)) => cancel = "";

  [@bs.send] external onSnapshotWithOptions : (DocumentReference.t, snapshotListenSettings, observer('a)) => cancel = "onSnapshot";

  [@bs.send] external onSnapshotWithCallbacks : (DocumentReference.t,
    ~onNext: DocumentSnapshot.t => _,
    ~onError: Js.t('a) => _ = ?,
    ~onCompletion: unit => _ = ?,
    unit
  ) => cancel = "onSnapshot";

  [@bs.send] external onSnapshotWithCallbacksAndOptions : (DocumentReference.t,
    ~options:snapshotListenSettings,
    ~onNext: DocumentSnapshot.t => _,
    ~onError: Js.t('a) => _ = ?,
    ~onCompletion: unit => _ = ?,
    unit
  ) => cancel = "onSnapshot";

  [@bs.send] external set : (DocumentReference.t, Js.t('a), ~options : setSettings = ?) => Js.Promise.t(_) = "";

  [@bs.send] external update : (DocumentReference.t, Js.t('a)) => Js.Promise.t(_) = "";

  [@bs.send] [@bs.variadic] external updateMultipleFields : (DocumentReference.t, array('a)) => Js.Promise.t(_) = "update";
};

module QuerySnapshot = {
  type t;
};

module Query = {
  type t;

  type observer('a) = Js.t('a);

  type cancel = unit => unit;

  [@bs.get] external firestore : t => Firestore.t = "";

  [@bs.send] external endAt : (t, DocumentSnapshot.t) => t = "";

  [@bs.send] [@bs.variadic] external endAtMultipleFields : (t, array('a)) => t = "endAt";

  [@bs.send] external endBefore : (t, DocumentSnapshot.t) => t = "";

  [@bs.send] [@bs.variadic] external endBeforeMultipleFields : (t, array('a)) => t = "endBefore";

  [@bs.send] external get : (t, getSettings) => Js.Promise.t(QuerySnapshot.t) = "";

  [@bs.send] external isEqual : (t, t) => bool = "";

  [@bs.send] external limit : (t, int) => t = "";

  [@bs.send] external onSnapshot : (t, observer('a)) => cancel = "";

  [@bs.send] external onSnapshotWithOptions : (t, snapshotListenSettings, observer('a)) => cancel = "onSnapshot";

  [@bs.send] external onSnapshotWithCallbacks : (t,
    ~onNext: QuerySnapshot.t => _,
    ~onError: Js.t('a) => _ = ?,
    ~onCompletion: unit => _ = ?,
    unit
  ) => cancel = "onSnapshot";

  [@bs.send] external onSnapshotWithCallbacksAndOptions : (t,
    ~options:snapshotListenSettings,
    ~onNext: QuerySnapshot.t => _,
    ~onError: Js.t('a) => _ = ?,
    ~onCompletion: unit => _ = ?,
    unit
  ) => cancel = "onSnapshot";

  [@bs.send] external orderBy : (t, string, ~direction: [@bs.string] [
    | [@bs.as "asc"] `Ascend
    | [@bs.as "desc"] `Descend
  ] = ?, unit) => t = "";

  [@bs.send] external startAfter : (t, DocumentSnapshot.t) => t = "";

  [@bs.send] [@bs.variadic] external startAfterMultipleFields : (t, array('a)) => t = "startAfter";

  [@bs.send] external startAt : (t, DocumentSnapshot.t) => t = "";

  [@bs.send] [@bs.variadic] external startAtMultipleFields : (t, array('a)) => t = "startAt";
};

module Transaction = {
  type t;

  [@bs.send] external delete : (t, DocumentReference.t) => t = "";

  [@bs.send] external get : (t, DocumentReference.t) => Js.Promise.t(DocumentSnapshot.t) = "";

  [@bs.send] external set : (t, DocumentReference.t, Js.t('a), ~options: setSettings) => t = "";

  [@bs.send] external update : (t, DocumentReference.t, Js.t('a)) => t = "";

  [@bs.send] [@bs.variadic] external updateMultipleFields : (t, DocumentReference.t, array('a)) => t = "update";
};

module WriteBatch = {
  type t;

  [@bs.send] external commit : t => Js.Promise.t(_) = "";

  [@bs.send] external delete : (t, DocumentReference.t) => t = "";

  [@bs.send] external set : (t, DocumentReference.t, Js.t('a), ~options: setSettings) => t = "";

  [@bs.send] external update : (t, DocumentReference.t, Js.t('a)) => t = "";

  [@bs.send] [@bs.variadic] external updateMultipleFields : (t, DocumentReference.t, array('a)) => t = "update";
};

module Collection = {
  type observer('a) = Js.t('a);

  type cancel = unit => unit;

  [@bs.get] external firebase : CollectionReference.t => Firestore.t = "";

  [@bs.get] external id : CollectionReference.t => string = "";

  [@bs.get] external parent : CollectionReference.t => Js.Nullable.t(DocumentReference.t) = "";

  [@bs.get] external path : CollectionReference.t => string = "";

  [@bs.send] external add : (CollectionReference.t, Js.t('a)) => Js.Promise.t(DocumentReference.t) = "";

  [@bs.send] external doc : (CollectionReference.t, string) => DocumentReference.t = "";

  [@bs.send] external endAt : (CollectionReference.t, DocumentSnapshot.t) => Query.t = "";

  [@bs.send] [@bs.variadic] external endAtMultipleFields : (CollectionReference.t, array('a)) => Query.t = "endAt"

  [@bs.send] external endBefore : (CollectionReference.t, DocumentSnapshot.t) => Query.t = "";

  [@bs.send] [@bs.variadic] external endBeforeMultipleFields : (CollectionReference.t, array('a)) => Query.t = "endAt";

  [@bs.send] external get : (CollectionReference.t, getSettings) => Js.Promise.t(QuerySnapshot.t) = "";

  [@bs.send] external isEqual : (CollectionReference.t, CollectionReference.t) => bool = "";

  [@bs.send] external limit : (CollectionReference.t, int) => Query.t = "";

  [@bs.send] external onSnapshot : (CollectionReference.t, observer('a)) => cancel = "";

  [@bs.send] external onSnapshotWithOptions : (CollectionReference.t, snapshotListenSettings, observer('a)) => cancel = "onSnapshot";

  [@bs.send] external onSnapshotWithCallbacks : (CollectionReference.t,
    ~onNext: QuerySnapshot.t => _,
    ~onError: Js.t('a) => _ = ?,
    ~onCompletion: unit => _ = ?,
    unit
  ) => cancel = "onSnapshot";

  [@bs.send] external onSnapshotWithCallbacksAndOptions : (CollectionReference.t,
    ~options:snapshotListenSettings,
    ~onNext: QuerySnapshot.t => _,
    ~onError: Js.t('a) => _ = ?,
    ~onCompletion: unit => _ = ?,
    unit
  ) => cancel = "onSnapshot";

  [@bs.send] external orderBy : (CollectionReference.t, string, ~direction: [@bs.string] [
    | [@bs.as "asc"] `Ascend
    | [@bs.as "desc"] `Descend
  ] = ?, unit) => Query.t = "";

  [@bs.send] external startAfter : (CollectionReference.t, DocumentSnapshot.t) => Query.t = "";

  [@bs.send] [@bs.variadic] external startAfterMultipleFields : (CollectionReference.t, array('a)) => Query.t = "startAfter";

  [@bs.send] external startAt : (CollectionReference.t, DocumentSnapshot.t) => Query.t = "";

  [@bs.send] [@bs.variadic] external startAtMultipleFields : (CollectionReference.t, array('a)) => Query.t = "startAt";

  [@bs.send] external where : (CollectionReference.t, string, [@bs.string] [
    | [@bs.as "<"] `LessThan
    | [@bs.as "<="] `LessThanOrEqual
    | [@bs.as ">"] `GreaterThan
    | [@bs.as ">="] `GreaterThanOrEqual
    | [@bs.as "=="] `Equal
    | [@bs.as "array-contains"] `ArrayContain
  ], 'a) => Query.t = "";
};

module Make = (App: Firebase_App.App) => {
  [@bs.send] external firestore : App.t => Firestore.t = "firestore";
  let instance = firestore(App.instance);

  [@bs.get] external app : Firestore.t => App.t = "";

  [@bs.send] external batch : Firestore.t => WriteBatch.t = "";

  [@bs.send] external collection : (Firestore.t, string) => CollectionReference.t = "";

  [@bs.send] external disableNetwork : Firestore.t => Js.Promise.t(_) = "";

  [@bs.send] external get : (Firestore.t, string) => DocumentReference.t = "";

  [@bs.send] external enableNetwork : Firestore.t => Js.Promise.t(_) = "";

  [@bs.send] external enablePersistence : (Firestore.t, ~settings : persistenceSettings = ?) => Js.Promise.t(_) = "";

  [@bs.send] external runTransaction : (Firestore.t, Transaction.t => Js.Promise.t('a)) => Js.Promise.t('a) = "";

  [@bs.send] external settings : (Firestore.t, firebaseSettings) => _ = "";
};