import { BrowserRouter as Router, Routes, Route, Link } from "react-router-dom";
import Home from "./routes/Home";
import Detail from "./routes/Detail";
import styles from "./styles/main.module.css";

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/movie/:id" element={<Detail />}/>
        <Route path="/" element={<Home />}/>
      </Routes>
    </Router>
  );
}

export default App;