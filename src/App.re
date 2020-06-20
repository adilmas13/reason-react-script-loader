[@react.component]
let make = () => {
  let (message, setMessage) = React.useState(() => "Script not loaded");

  let loadScript = (_, src) => {
    let script: ScriptLoader.script = {
      id: "my-sample-js",
      src,
      async: true,
      defer: true,
    };

    ScriptLoader.load(script, result => {
      switch (result) {
      | SUCCESS => setMessage(_ => "Script Loaded Successfully")
      | ERROR => setMessage(_ => "Script Loading Failed")
      }
    });
  };

  let checkIfScriptIfLoaded = (_, src) => {
    let script: ScriptLoader.script = {
      id: "my-sample-js",
      src,
      async: true,
      defer: true,
    };
    Js.log(ScriptLoader.isScriptLoaded(script.src));
    ();
  };

  <>
    <button onClick={__x => loadScript(__x, "./src/Sample.js")}>
      {ReasonReact.string("Demonstrate Successful script Loading")}
    </button>
    <button onClick={__x => loadScript(__x, "./src/NotExisting.js")}>
      {ReasonReact.string("Demonstrate Failed script Loading")}
    </button>
    <button onClick={__x => checkIfScriptIfLoaded(__x, "./src/Sample.js")}>
      {ReasonReact.string("Check if script is loaded")}
    </button>
    <div> {ReasonReact.string(message)} </div>
  </>;
};