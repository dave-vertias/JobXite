const express = require("express");
const app = express(); 
const cors = require("cors");
const pool = require("./db");

app.use(cors());
app.use(express.json());

//create a job
app.post("/jobs", async(req, res) => {
    try {
        console.log(req.body);
    } catch(err) {
        console.error(err.message);
    }
    });

//get all jobs

//get a job (lol)

//update a job

//delete a job


app.listen(/*insert port number here*/, () => {
    
    console.log("Server is now listening");
});


