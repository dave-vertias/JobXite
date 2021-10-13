
//HEAVILY CONSIDERING rewriting all of this from scratch in C, instead of using a framework,
//Using express is a good way to very quickly get a web application live because it's
//a Web Application Framework. 

// Reasons I'm considering switching to C/C++:
//
// #1 I am not familiar with system calls in JS, very familair with them in C
// System calls will be very important for a microservice arch or integration with
// python/other language processes
//
// #2 Performance....
//
// #3 Any framework is a dependency, an update to express could break our service (we WILL be updating it for security reasons).

// #4 I am more productive in C, much better with the language. 


const express = require("express");
// app is return object of express, simple web app framework that handles
// socket network programming and tedium. 
const app = express(); 
//it's convention to call this object app....
const cors = require("cors");
//Cross Origin Resource Sharing, very unsafe but makes stuff easy a frist. 
const pool = require("./db");
//db.js is our database handling logic

//these requires are specific to NodeJS and basically are like python imports

app.use(cors());
//this adds a response header to our HTTP responses that lets us have unsafe HTTP comunication
//its basically a lazy shortcut.... whatever. 
app.use(express.json());
//this is just calling the use function on the app object we created
//you can refer to the express documentation to learn
//what functions you can call on the app object
//express.json in app.use tells us to use the json parser built into express framework
//basically tells the process to expect json packets

//create a job
app.post("/jobs", async(req, res) => {
    try {
        console.log(req.body);
    } catch(err) {
        console.error(err.message);
    }
    });

//this is where middleware functions would go, you need to refer to the express
//documentation to see how to implement responses to network communication we care about
//
//
//we need functionality like:
//get all jobs

//get a job

//update a job

//delete a job


app.listen(25565, () => {
    //while loop, waiting for network communication. 
    console.log("Server is now listening");
});


