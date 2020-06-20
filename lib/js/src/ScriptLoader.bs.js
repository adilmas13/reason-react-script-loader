'use strict';

var Curry = require("bs-platform/lib/js/curry.js");

function isScriptLoaded(src) {
  var query = "script[src=\"" + (String(src) + "\"]");
  var temp = document.querySelector(query);
  return temp !== null;
}

function load(script, callback) {
  if (isScriptLoaded(script.src)) {
    return Curry._1(callback, /* SUCCESS */0);
  }
  var element = document.createElement("script");
  element.id = script.id;
  element.type = "text/javascript";
  element.src = script.src;
  if (script.async) {
    element.async = true;
  }
  if (script.defer) {
    element.defer = true;
  }
  element.onload = (function (param) {
      return Curry._1(callback, /* SUCCESS */0);
    });
  element.onerror = (function (param) {
      return Curry._1(callback, /* ERROR */1);
    });
  document.head.append(element);
  
}

exports.isScriptLoaded = isScriptLoaded;
exports.load = load;
/* No side effect */
