import { useState, useEffect } from "react";

function App() {
  const [toDo, setToDo] = useState("");
  const [toDos, setToDos] = useState([]);
  const onChange = (event) => setToDo(event.target.value);
  const onSubmit = (event) => {
    event.preventDefault(); 
    if (toDo === ""){
      return;
    }
    setToDo("");
    //아래는 
    //setToDos(function (currentArray){})
    //와 동일
    setToDos(currentArray => [toDo, ...currentArray]);
  }

  useEffect(() => console.log(toDos),[toDos]);
  
  return (
    <div>
      <form onSubmit={onSubmit}>
        <input
          onChange={onChange}
          value={toDo}
          type="text"
          placeholder="Write your to do..."
        />
        <button>
          Add To Do
        </button>
      </form>
    </div>
  );
}

export default App;
