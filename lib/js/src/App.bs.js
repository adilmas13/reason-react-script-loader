'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ScriptLoader$ReasonReactExamples = require("./ScriptLoader.bs.js");

function App(Props) {
  var match = React.useState((function () {
          return "Script not loaded";
        }));
  var setMessage = match[1];
  var loadScript = function (param, src) {
    var script = {
      id: "my-sample-js",
      src: src,
      async: true,
      defer: true
    };
    return ScriptLoader$ReasonReactExamples.load(script, (function (result) {
                  if (result) {
                    return Curry._1(setMessage, (function (param) {
                                  return "Script Loading Failed";
                                }));
                  } else {
                    return Curry._1(setMessage, (function (param) {
                                  return "Script Loaded Successfully";
                                }));
                  }
                }));
  };
  return React.createElement(React.Fragment, undefined, React.createElement("button", {
                  onClick: (function (__x) {
                      return loadScript(__x, "./src/Sample.js");
                    })
                }, "Demonstrate Successful script Loading"), React.createElement("button", {
                  onClick: (function (__x) {
                      return loadScript(__x, "./src/NotExisting.js");
                    })
                }, "Demonstrate Failed script Loading"), React.createElement("button", {
                  onClick: (function (__x) {
                      var src = "./src/Sample.js";
                      console.log(ScriptLoader$ReasonReactExamples.isScriptLoaded(src));
                      
                    })
                }, "Check if script is loaded"), React.createElement("div", undefined, match[0]));
}

var make = App;

exports.make = make;
/* react Not a pure module */
