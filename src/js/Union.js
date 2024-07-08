async function lookupCharacter() {
    const apiKey = 'test_cf92cd14930e08e300ab26408fc39a04106ffd90a4270419752ce5af9d9627efefe8d04e6d233bd35cf2fabdeb93fb0d';
    const characterName = document.getElementById('characterName').value;
    const url = `https://api.nexon.co.kr/maplestory/v1/id?character_name=${encodeURIComponent(characterName)}`;
    
    try {
        const response = await fetch(url, {
            method: 'GET',
            headers: {
                'x-nxopen-api-key': apiKey
            }
        });
        
        if (!response.ok) {
            throw new Error('Network response was not ok ' + response.statusText);
        }

        const data = await response.json();
        document.getElementById('result').innerText = `OCID: ${data.ocid}`;
    } catch (error) {
        document.getElementById('result').innerText = `Error: ${error.message}`;
    }
}