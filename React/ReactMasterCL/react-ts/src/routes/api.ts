const BASE_URL = `https://api.coinpaprika.com/v1`;

export function fetchCoins() {
  return fetch(`${BASE_URL}/coins`).then((response) => response.json());
}

export function fetchCoinInfo() {
  return fetch(`${BASE_URL}/coins/${coinId}`).then((response) => response.json());
}
