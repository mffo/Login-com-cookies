<?php

if(isset($_COOKIE['email_usuario']))
	$email_usuario = $_COOKIE['email_usuario'];
if(isset($_COOKIE['senha_usuario']))
	$senha_usuario = $_COOKIE['senha_usuario'];

if(!empty($email_usuario) OR !empty($senha_usuario)){
	
	include "conecta_mysql.inc";
	$email_usuario = $conexao->real_escape_string($email_usuario);
	$senha_usuario = $conexao->real_escape_string($senha_usuario);
	

	$resultado = $conexao->query("SELECT * FROM usuarios WHERE '$senha_usuario'= senha AND '$email_usuario'=email");
	$linhas = $resultado->num_rows;
	if($linhas==0){
		setcookie("email_usuario");
		setcookie("senha_usuario");
		echo "Você não efetuou o login!";
		exit();
	}
}else{
    echo "Você não efetuou o <a href='login.html'>login</a>!";
    exit();	
}
$conexao->close();
?>