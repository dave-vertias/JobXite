const Pool = require("pg").Pool;
//pool is function specified by the node-postgres package to interface with PostgreSQL

//This gives database information
const pool = new Pool({
    user: "postgres",
    password: "daveRocks!96",
    host: "localhost",
    port: 5432,
    database: "jobs"
});

module.export = pool;
