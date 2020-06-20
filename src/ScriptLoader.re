//  isScriptLoaded = (script) => document.querySelector(`script[src="${script.src}"]`) !== null
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
[@bs.val] [@bs.scope "document"]
external isLoaded: string => Js.Nullable.t(element) = "querySelector";

type script = {
  id: string,
  src: string,
  async: bool,
  defer: bool,
};

type scriptLoadResult =
  | SUCCESS
  | ERROR;

let isScriptLoaded = (src: string) => {
  let query = {j|script[src="$src"]|j};
  let temp = isLoaded(query);
  !(temp == Js.Nullable.null);
};

let load = (script: script, callback: scriptLoadResult => unit) =>
  if (isScriptLoaded(script.src)) {
    // if the script is already loaded pass back a success
    callback(SUCCESS);
  } else {
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