[@bs.module "firebase"] external sdkVersion : string = "SDK_VERSION";
[@bs.module "firebase"] external apps : _ = "apps";

module App = Firebase_App
module Database = Firebase_Database
module Firestore = Firebase_Firestore