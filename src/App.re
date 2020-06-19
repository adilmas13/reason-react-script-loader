[@react.component]
let make = () => {

  let (message, setMessage)= React.useState(() => "Script not loaded") 

  let loadScript = (_, src) => {
        let script: ScriptLoader.script = {
          id: "my-sample-js",
          src: src,
          async: true,
          defer: true,
        };

        ScriptLoader.load(script, result => {
          switch (result) {
          | SUCCESS => setMessage(_ => "Script Loaded Successfully")
          | ERROR => setMessage(_ => "Script Loading Failed");
          }
        });
  };
  <>
    <button onClick=loadScript(_, "./src/Sample.js")> {ReasonReact.string("Demonstrate Successful script Loading")} </button>
    <button onClick=loadScript(_, "./src/NotExisting.js")> {ReasonReact.string("Demonstrate Failed script Loading")} </button>
    <div>{ReasonReact.string(message)}</div>
  </>;
};