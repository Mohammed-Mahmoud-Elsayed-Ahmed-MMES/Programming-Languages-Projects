/* One => لديك ال JSON Object التالي
بإستخدام ما تعلمته نحتاج لطباعة الشكل كما في الصورة الموجودة بالأسفل
لاحظ أننا طبعنا 5 مقالات فقط بدلا من 10
يجب إستخدام ال Promises لعمل المطلوب
const getData = (apilink) => {
    return new Promise((resolve,reject) => {
        const myRequest = new XMLHttpRequest();
        myRequest.onload = function()
        {
            if(this.readyState === 4 && this.status === 200)
            {
                resolve(JSON.parse(this.responseText));
            }else{
                reject(Error("No Data Found"));
            }
        };
        myRequest.open("GET",apilink);
        myRequest.send();
    });
};

getData("./jason.json")
    .then((result) => {
        result.length = 5;
        return result;
    })
    .then((result) => {
        for(let i=0; i < result.length ;i++)
        {
            const title = document.createElement("h3");
            const titleText = document.createTextNode((result[i].title));
            title.appendChild(titleText);

            let description = document.createElement("p");
            let descriptionText = document.createTextNode(result[i].description);
            description.appendChild(descriptionText);

            const div = document.createElement("div")
            div.appendChild(title);
            div.appendChild(description);
            document.body.appendChild(div);
        }
    }).catch((rej) => {
        return(rej);
    })
*/

/* Two => First Way
fetch("./jason.json")
    .then((result) => {
    console.log(result);
    let myData = result.json();
    console.log(myData);
    return myData;
    })
    .then((full) => {
    full.length = 5;
    return full;
    })
    .then((ten) => {
        for(let i=0; i < ten.length ;i++)
        {
            const title = document.createElement("h3");
            const titleText = document.createTextNode((ten[i].title));
            title.appendChild(titleText);

            let description = document.createElement("p");
            let descriptionText = document.createTextNode(ten[i].description);
            description.appendChild(descriptionText);

            const div = document.createElement("div")
            div.appendChild(title);
            div.appendChild(description);
            document.body.appendChild(div);
        }
    });
*/


/* Two => Second Way
async function fetchData()
{
    try
    {
        let myData = await fetch("./jason.json");
        let data = await myData.json();
        data.length = 5;
        for(let i=0; i < data.length ;i++)
        {
            const title = document.createElement("h3");
            const titleText = document.createTextNode((data[i].title));
            title.appendChild(titleText);

            let description = document.createElement("p");
            let descriptionText = document.createTextNode(data[i].description);
            description.appendChild(descriptionText);

            const div = document.createElement("div")
            div.appendChild(title);
            div.appendChild(description);
            document.body.appendChild(div);
        }
    }catch(error){
        console.log("No Data Found");
    }
};
fetchData();
*/