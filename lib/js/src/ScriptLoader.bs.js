'use strict';

var Curry = require("bs-platform/lib/js/curry.js");

function load(script, callback) {
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

exports.load = load;
/* No side effect */
