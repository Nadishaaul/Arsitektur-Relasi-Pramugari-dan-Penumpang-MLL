#!/bin/bash

# Auto Push to GitHub Script (Bash version)
# This script automatically commits and pushes changes to GitHub

COMMIT_MESSAGE="Auto commit from Bash script"

# Check if commit message is provided as argument
if [ $# -gt 0 ]; then
    COMMIT_MESSAGE="$*"
fi

# Check if git is installed
if ! command -v git &> /dev/null; then
    echo "Git is not installed. Please install Git first."
    exit 1
fi

# Check if this is a git repository
if [ ! -d ".git" ]; then
    echo "This is not a Git repository. Please initialize Git first."
    exit 1
fi

# Check git status
if [ -z "$(git status --porcelain)" ]; then
    echo "No changes to commit."
    exit 0
fi

# Add all changes
echo "Adding changes..."
git add .

# Commit changes
echo "Committing changes..."
if git commit -m "$COMMIT_MESSAGE"; then
    echo "Commit successful."
else
    echo "Commit failed. Please check for errors."
    exit 1
fi

# Push to remote
echo "Pushing to GitHub..."
if git push; then
    echo "Successfully pushed to GitHub!"
else
    echo "Push failed. Please check your remote configuration and network."
    exit 1
fi