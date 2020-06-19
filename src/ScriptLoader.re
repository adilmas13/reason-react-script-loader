type element;
[@bs.val] [@bs.scope "document"] external head: element = "head";
[@bs.val] [@bs.scope "document"]
external createElement: ([@bs.string] [ | `script | `link]) => element =
  "createElement";
[@bs.set]
external setType:
  (element, [@bs.string] [ | [@bs.as "text/javascript"] `text_javascript]) =>
  unit =
  "type";
[@bs.set] external setSource: (element, string) => unit = "src";
[@bs.set] external setId: (element, string) => unit = "id";
[@bs.set] external setAysnc: (element, bool) => unit = "async";

[@bs.set] external setDefer: (element, bool) => unit = "defer";
[@bs.set] external setOnLoad: (element, unit => unit) => unit = "onload";
[@bs.set] external setOnError: (element, unit => unit) => unit = "onerror";
[@bs.send] external appendChild: (element, element) => unit = "append";

type script = {
  id: string,
  src: string,
  async: bool,
  defer: bool,
};

type scriptLoadResult =
  | SUCCESS
  | ERROR;

let load = (script: script, callback: scriptLoadResult => unit) => {
  let element = createElement(`script);
  setId(element, script.id);
  setType(element, `text_javascript);
  setSource(element, script.src);

  if (script.async) {
    setAysnc(element, true);
  };

  if (script.defer) {
    setDefer(element, true);
  };

  setOnLoad(element, () => callback(SUCCESS));
  setOnError(element, () => callback(ERROR));
  appendChild(head, element);
};
