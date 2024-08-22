import { useState, useEffect } from "react";
import styles from "./todo.module.css"

function App() {
  const [toDo, setToDo] = useState("");
  const [toDos, setToDos] = useState([]);
  const onChange = (event) => setToDo(event.target.value);
  const onSubmit = (event) => {
    event.preventDefault();
    if (toDo === "") {
      return;
    }
    setToDos((currentArray) => [toDo, ...currentArray]);
    setToDo("");
  };

  useEffect(() => console.log(toDos), [toDos]);

  return (
    <div className={styles.main}>
      <h1 className={styles.title}>SeHi 의 ToDo 리스트</h1>
      <form className={styles.inputForm} onSubmit={onSubmit}>
        <input
          onChange={onChange}
          value={toDo}
          type="text"
          placeholder="할 일을 적어 주세요..."
        />
        <button>추가</button>
      </form>
      <hr />
      <ul>
        {toDos.map((item, index) => (
          <li key={index}>{item}</li>
        ))}
      </ul>
      <hr />
      <p>개수 : {toDos.length}</p>
    </div>
  );
}

export default App;
