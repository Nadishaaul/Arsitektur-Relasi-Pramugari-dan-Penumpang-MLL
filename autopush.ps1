# Auto Push to GitHub Script
# This script automatically commits and pushes changes to GitHub

param(
    [string]$CommitMessage = "Auto commit from PowerShell script"
)

# Check if git is installed
if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    Write-Host "Git is not installed. Please install Git first." -ForegroundColor Red
    exit 1
}

# Check if this is a git repository
if (-not (Test-Path ".git")) {
    Write-Host "This is not a Git repository. Please initialize Git first." -ForegroundColor Red
    exit 1
}

# Check git status
$status = git status --porcelain
if ($status -eq $null -or $status -eq "") {
    Write-Host "No changes to commit." -ForegroundColor Yellow
    exit 0
}

# Add all changes
Write-Host "Adding changes..." -ForegroundColor Green
git add .

# Commit changes
Write-Host "Committing changes..." -ForegroundColor Green
git commit -m $CommitMessage

# Check if commit was successful
if ($LASTEXITCODE -ne 0) {
    Write-Host "Commit failed. Please check for errors." -ForegroundColor Red
    exit 1
}

# Push to remote
Write-Host "Pushing to GitHub..." -ForegroundColor Green
git push

# Check if push was successful
if ($LASTEXITCODE -ne 0) {
    Write-Host "Push failed. Please check your remote configuration and network." -ForegroundColor Red
    exit 1
}

Write-Host "Successfully pushed to GitHub!" -ForegroundColor Green