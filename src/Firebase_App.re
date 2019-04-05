[@bs.obj] external options : (
  ~apiKey : string = ?,
  ~projectId : string = ?,
  ~authDomain : string = ?,
  ~databaseURL : string = ?,
  ~storageBucket : string = ?,
  unit
) => Js.t('a) = "";

module type App = {
  type t;

  let instance : t;
  let name : string;
  let options : Js.t('a);
};

module type Configuration = {
  let name : string;

  let options : Js.t('a);
};

module Make = (Config: Configuration) => {
  type t;

  [@bs.module "firebase"] external make : (~options: Js.t('a), ~name:string=?, unit) => t = "initializeApp";

  let instance = make(~options=Config.options, ~name=Config.name, ());

  [@bs.get] external name : t => string = "";

  let name = name(instance);

  [@bs.get] external options : t => _ = "";

  let options = options(instance);
};
