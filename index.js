/*
Cerinta este urmatoarea:
Se dă API-ul documentat aici https://socialinsider.docs.apiary.io/ și API-key-ul API_KEY_TEST

Din parametrii: projectname=API_test
Metodele din API de care vei avea nevoie sunt: socialinsider_api.get_brands și socialinsider_api.get_profile_data

Cerința:

Vei implementa un backend - să spunem  "Brand Compare Backend", care consumă API-ul de mai sus.

O pagină HTML care face requesturi la backendul definit de tine  "Brand Compare Backend", 
care apoi face requesturile către API-ul nostru, prin care ia date astfel incât să se afișeze un tabel 
cu toate brandurile din proiect - parametrul date din requestul către get_brand_data trebuie ales dintr-un date-picker. 
La schimbarea datei ar trebui ca viewul să își facă un refresh cu datele noi.

Tabelul va avea pe fiecare linie un brand și coloanele sunt: Brand Name, Total Profiles(numărul total de profile din brand - key-ul profiles), 
Total Fans(suma fieldului fans din brand), Total Engagement(suma fieldului engagement pentru toate profilele din brand)

Pentru frontend: Orice javascript framework
Pentru backend: Orice

*/
var data;

// connection at port 8080
const api_url = "https://app.socialinsider.io/api";
const axios = require('axios').default;

const express = require('express');
const app = express();
app.use(express.json());
app.listen(8080, () => console.log('Listening at 8080'));

let axiosConfig = {
    headers: {
        'Content-Type': 'application/json',
        'Authorization': 'Bearer API_KEY_TEST',
    }
};

async function postData(url = '', data = {}) {
    // Default options are marked with *
    const response = await axios(url, data, axiosConfig);
   return response; // parses JSON response into native JavaScript objects
  };


postData(api_url, {
    "jsonrpc": "2.0", 
    "id": 0,
    "method": "socialinsider_api.get_profiles", 
    "params": {
        "projectname": "API_test"
    }
}, axiosConfig)
.then(data => {
      console.log(data); // JSON data parsed by `data.json()` call
    })
.catch( (error) => {
    console.log(error);
});


    
function showData(data){
    let tab = `<tr>
        <th>Brand Name</th>
        <th>Total Profiles</th>
        <th>Total Fans</th>
        <th>Total Engagement</th>
    </tr>`

    for(let br of data.get_brands()){
        let br_dat = br.get_profile_data();

        let total_profiles = 0;
        
        for(let i of br_dat.profiles){
            total_profiles += 1;
        }

        tab += `<tr>
        <th>${br_dat.brand_name}</th>
        <th>${total_profiles}</th>
        </tr>`
    }
}

//showData(data);
