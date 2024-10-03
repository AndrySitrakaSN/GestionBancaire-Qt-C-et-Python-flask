from flask import Flask, render_template, request, redirect, url_for, session
import sqlite3

app = Flask(__name__)
app.secret_key = 'f3c2d3f59a4e1b5e9876543210abc123'  # Remplacez par une clé aléatoire et unique


# Fonction pour se connecter à la base de données
def get_db_connection():
    conn = sqlite3.connect('database.db')
    conn.row_factory = sqlite3.Row  # Pour accéder aux colonnes par nom
    return conn

# Page d'accueil
@app.route('/')
def home():
    return render_template('login.html')

# Page de connexion
@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']
    
    conn = get_db_connection()
    user = conn.execute('SELECT * FROM client WHERE nom = ? AND mots_de_pass = ?', (username, password)).fetchone()
    conn.close()

    if user:
        session['user_id'] = user['id']  # Enregistrer l'ID de l'utilisateur dans la session
        return redirect(url_for('dashboard'))
    else:
        return "Identifiants invalides", 401

# Page de consultation du solde
@app.route('/dashboard')
def dashboard():
    if 'user_id' not in session:
        return redirect(url_for('home'))
    
    user_id = session['user_id']
    conn = get_db_connection()
    user = conn.execute('SELECT * FROM client WHERE id = ?', (user_id,)).fetchone()
    conn.close()

    # Passer les informations de l'utilisateur au template
    return render_template('dashboard.html', 
                           nom=user['nom'],
                           prenom=user['prenom'],
                           email=user['email'],
                           telephone=user['telephone'],
                           adresse=user['adresse'],
                           solde=user['solde'])


# Déconnexion
@app.route('/logout')
def logout():
    session.pop('user_id', None)
    return redirect(url_for('home'))

"""
if __name__ == '__main__':
    app.run(debug=True)

"""
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)

