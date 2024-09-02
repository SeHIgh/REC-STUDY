import { useState, useEffect } from "react";

function App() {
  const [counter, setValue] = useState(0);
  const onClick = () => setValue((prev) => prev + 1);
  const [keyword, setKeyword] = useState("");
  const onChange = (event) => setKeyword(event.target.value);

  useEffect(() => {
    console.log("I run only once.");
  }, []);

  useEffect(() => {
    if (counter > 0){
      console.log("I run when 'counter' changes.");
    }
  }, [counter]);

  useEffect(() => {
    if (keyword != "" && keyword.length > 5) {
      console.log("Search for", keyword);
    }
  }, [keyword]);

  return (
    <div>
      <input
        value={keyword}
        type="text"
        onChange={onChange}
        placeholder="Search here..."
      ></input>
      <h1>{counter}</h1>
      <button onClick={onClick}>click me</button>
    </div>
  );
}

export default App;
