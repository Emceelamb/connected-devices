const SECRETS = require('./secrets');
const Pool = require('pg').Pool;

const pool = new Pool({
    user: 'postgres',
    host: SECRETS.DB_HOST,
    database: 'api',
    password: 'D!ablo23$',
    port: SECRETS.DB_PORT,
});

const getUsers = (req, res) => {
    pool.query('SELECT * FROM users ORDER BY id ASC', (error, result)=> {
        if(error){
            throw error;
        } 
        res.status(200).json(result.rows);
    });
}

const getUserById = (req,res)=>{
    const id = parseInt(req.params.id);

    pool.query('SELECT * FROM users WHERE id = $1', [id], (err, result)=>{
        if(err){
            throw err
        }
        res.status(200).json(result.rows);
    })
};

//const createUser = (req, res)=>{
    //const {name,email}=req.body;
//    pool.query('INSERT INTO users (name, email) VALUES ($1,$2)', [name, email], error,results)=>{

    //pool.query('INSERT INTO users (name, email) VALUES ($1, $2)',[name,email, (err, result)=>{
      //  if(err){throw err;}
  //      res.status(201).send('User added with ID: ${result.insertId}');
//    })
//};

const createUser = (request, response) => {
  const { name, email } = request.body

  pool.query('INSERT INTO users (name, email) VALUES ($1, $2)', [name, email], (error, results) => {
    if (error) {
      throw error
    }
       console.log(results.rows[0].id);
       let newId=results.rows[1].id;
       response.status(201).send(`User added with ID: ${newId}`)
  })
}

const updateUser = (req, res)=>{
    const id = parseInt(req.params.id);
    const{name,email}=req.body;
    pool.query(
    'UPDATE users SET name = $1, email =$2 WHERE id = $3',
    [name, email, id],
    (error, results)=>{
        if (error){throw error}
        res.status(200).send(`user modified ID: ${id}`);
    }
    )
}


module.exports = {
    getUsers,
    getUserById,
    createUser,
    updateUser
}
