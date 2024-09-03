import { useState } from "react";
import styled from "styled-components";

interface CircleProps {
  bgColor: string;
}

const Container = styled.div<CircleProps>`
  width: 200px;
  height: 200px;
  background-color: ${(props) => props.bgColor};
  border-radius: 100px;
`;

function Circle({ bgColor }: CircleProps) {
//   const [value, setValue] = useState<number|string>(0);
//   setValue("hello");

  return <Container bgColor={bgColor} />;
}

export default Circle;

interface PlayerShape {
  name: string;
  age: number|string;
}

const sayHello = (playerObj: PlayerShape) =>
  alert(`Hello ${playerObj.name} you are ${playerObj.age} years old.`);

sayHello({ name: "sehi", age: 24 });
sayHello({ name: "sehi", age: "24" });