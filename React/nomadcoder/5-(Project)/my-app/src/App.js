import { useEffect, useState } from "react";

function App() {
  const [loading, setLoading] = useState(true);
  const [coins, setCoins] = useState([]);
  const [money, setMoney] = useState("");
  const [changed, setChanged] = useState(null);
  useEffect(() => {
    fetch("https://api.coinpaprika.com/v1/tickers")
      .then((response) => response.json())
      .then((json) => {
        setCoins(json);
        setLoading(false);
      });
  }, []);
  const onChange = (event) => setMoney(event.target.value);
  const moneyChange = (event) => {
    const selectedCoin = coins.find(
      (coin) => coin.id === event.target.value
    );
    setChanged(Math.floor(money / selectedCoin.quotes.USD.price));
  };
  return (
    <div>
      <h1>The Coins! {loading ? "" : `(${coins.length})`}</h1>
      {loading ? (
        <strong>Loading...</strong>
      ) : (
        <div>
          <input
            type="text"
            onChange={onChange}
            value={money}
            placeholder="코인 환전 원하는 달러 입력..."
          ></input>
          <select onChange={moneyChange}>
            <option value="">코인 선택...</option>
            {coins.map((coin) => (
              <option value={coin.id}>
                {coin.name} ({coin.symbol}): ${coin.quotes.USD.price} USD
              </option>
            ))}
          </select>
          <h3>{changed != null ? `${changed} 개` : null}</h3>
        </div>
      )}
    </div>
  );
}

export default App;
