# PayMint ER Diagram
```mermaid
erDiagram
    PLAYERS {
        int player_id PK
        string name
        int age
        string position
        int contract_status
        int team_level
    }
    
    CONTRACTS {
        int contract_id PK
        int player_id FK
        date start_date
        date end_date
        int base_salary
        string contract_type
        string renewal_option
    }
    
    SALARIES {
        int salary_id PK
        int player_id FK
        decimal gross_salary
        decimal net_salary
        string payment_frequency
        string currency
    }
    
    BONUSES {
        int bonus_id PK
        int player_id FK
        string bonus_type
        decimal amount
        string criteria_met
        date bonusPayment_date
    }
    
    TAX_DEDUCTIONS {
        int tax_id PK
        int player_id FK
        decimal tax_percentage
        decimal tax_ammount
        date deduction_date
    }
    
    PAYMENTS {
        int payment_id PK
        int player_id FK
        decimal amount_paid
        date payment_date
        string payment_method
    }
    
    FINANCE_REPORTS {
        int report_id PK
        date report_date
        decimal total_salaries_paid
        decimal total_bonuses_paid
        decimal taxes_deducted
    }
    
    PLAYERS ||--o{ CONTRACTS : "has"
    PLAYERS ||--o{ SALARIES : "receives"
    PLAYERS ||--o{ BONUSES : "earns"
    PLAYERS ||--o{ TAX_DEDUCTIONS : "applies"
    PLAYERS ||--o{ PAYMENTS : "receives"
    FINANCE_REPORTS ||--o{ PAYMENTS : "tracks"
    FINANCE_REPORTS ||--o{ TAX_DEDUCTIONS : "includes"
