Ce projet est une application de gestion bancaire composée de deux parties distinctes :

Application de bureau : Développée avec Qt (via PyQt ou PySide), cette application permet aux employés de la banque de gérer les comptes clients, d'ajouter ou de supprimer des transactions, et de mettre à jour les soldes dans la base de données locale SQLite.

Application web : Développée avec Flask, elle permet aux clients de consulter leur solde via une interface web simple et sécurisée. Flask interagit avec la base de données SQLite pour récupérer les informations sur les comptes clients.
