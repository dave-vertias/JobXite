const Pool = require("pg").Pool;

const pool = new Pool({
    user: "postgres",
    password: "00000",
    host: "localhost",
    port: 0000,
    database: "jobs"
});

module.export = pool;
